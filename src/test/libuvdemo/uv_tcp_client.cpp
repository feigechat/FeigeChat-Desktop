/** @file libuv_tcp_client.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/20
 */

#include "uv_tcp_client.h"

#include <atomic>
#include <iostream>
#include <memory>
#include <thread>
#include <unordered_map>

#include "uv.h"

using namespace std;

#ifdef USE_LIBUV_WRITE
typedef struct {
    uv_write_t req;
    uv_buf_t buf;
} write_req_t;
#endif

const int kInvalidSocket = -1;
static atomic_bool g_is_thread_loop_init_(false);
static std::unordered_map<int, UvTcpClientPtr> g_conn_map{};
static uv_timer_s *g_timer_ = nullptr;

void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
    buf->base = (char *)malloc(suggested_size);
    buf->len = suggested_size;
}

UvTcpClient::UvTcpClient()
    : tcp_handle_(nullptr)
    , sock_fd_(0)
    , connect_status_(ConnectionStatus::kDefault)
    , connection_cb_(nullptr)
    , message_cb_(nullptr) {}

UvTcpClient::~UvTcpClient() {
    cout << " deconstruct " << endl;

    close();
}

bool UvTcpClient::connect(const std::string &serverIp, uint16_t port) {
    close();

    assert(g_is_thread_loop_init_);

    tcp_handle_ = (uv_tcp_t *)malloc(sizeof(uv_tcp_t));
    int ret = uv_tcp_init(uv_default_loop(), tcp_handle_);
    if (ret == kInvalidSocket) {
        cout << "uv_tcp_init error:" << errno << endl;
        return false;
    }

    struct sockaddr_in remote_addr {};
    ret = uv_ip4_addr(serverIp.c_str(), port, &remote_addr);
    if (ret == kInvalidSocket) {
        cout << "uv_ip4_addr error:" << errno << endl;
        return false;
    }

    connect_status_ = ConnectionStatus::kConnecting;

    auto connect = (uv_connect_t *)malloc(sizeof(uv_connect_t));
    if (0 == uv_tcp_connect(connect, tcp_handle_, (const struct sockaddr *)&remote_addr, onConnect)) {
        // get socket fd
        uv_fileno((uv_handle_t *)tcp_handle_, &sock_fd_);
        g_conn_map[sock_fd_] = shared_from_this();

        cout << "connect to " << serverIp << ":" << port << ",fd=" << sock_fd_ << ",handle type=" << tcp_handle_->type
             << endl;
        return true;
    } else {
        cout << "connect error" << endl;
        close();
    }
    return false;
}

void UvTcpClient::close() {
    if (tcp_handle_ != nullptr) {
        uv_close((uv_handle_t *)tcp_handle_, nullptr);
        // libuv will free it?
        // free(tcp_handle_);
        tcp_handle_ = nullptr;
    }
    if (sock_fd_ != kInvalidSocket) {
        g_conn_map.erase(sock_fd_);
    }
    connect_status_ = ConnectionStatus::kDisConnected;
}

int UvTcpClient::send(const char *buff, int len) {
#ifdef USE_LIBUV_WRITE
    //    auto *req = (write_req_t *)malloc(sizeof(write_req_t));
    //
    //    char *tempBuf = static_cast<char *>(malloc(len));
    //    ::memcpy(tempBuf, buff, len);
    //    req->buf = uv_buf_init(tempBuf, len);
    //
    //    uv_write((uv_write_t *)req, (uv_stream_t *)tcp_handle_, &req->buf, 1, onWrite);
#else
    return ::send(sock_fd_, buff, len, 0);
#endif
}

void UvTcpClient::setConnectionCallback(const ConnectionCallback &cb) { connection_cb_ = cb; }

void UvTcpClient::setMessageCallback(const MessageCallback &cb) { message_cb_ = cb; }

void UvTcpClient::setConnectionStatus(ConnectionStatus status) {
    connect_status_ = status;
    if (connection_cb_) {
        connection_cb_(shared_from_this(), connect_status_);
    }
}

void UvTcpClient::onTimer() {}

void UvTcpClient::onTimer(uv_timer_s *timer) {
    // std::cout << "timer from libuv, id=" << timer->start_id << ",time=" << time(nullptr) << std::endl;
    for (auto &item : g_conn_map) {
        item.second->onTimer();
    }
}

void UvTcpClient::onConnect(uv_connect_s *req, int status) {
    if (status == 0) {
        cout << "connect success" << endl;

        auto tcpClient = findTcpClient(req->handle);
        if (tcpClient != nullptr) {
            tcpClient->setConnectionStatus(ConnectionStatus::kConnected);
        }

        // 注册read事件
        uv_read_start(req->handle, alloc_buffer, onRead);
    } else {
        cout << "connection lost, changed to " << status << endl;
        auto tcpClient = findTcpClient(req->handle);
        if (tcpClient != nullptr) {
            tcpClient->close();
            tcpClient->setConnectionStatus(ConnectionStatus::kDisConnected);
        }
    }
}

#if USE_LIBUV_WRITE
void UvTcpClient::onWrite(uv_write_s *req, int status) {
    if (status == 0) {
        // cout << "write succeed!" << endl;
    } else {
        cout << "write error:" << status << endl;
        // uv_close((uv_handle_t*)req,NULL);
    }

    auto *wr = (write_req_t *)req;
    free(wr->buf.base);
    free(wr);
}
#endif

void UvTcpClient::onRead(uv_stream_s *client, ssize_t nread, const uv_buf_t *buf) {
    if (nread > 0) {
        // cout << "recv len=" << nread << ",bff_size=" << buf->len << endl;

        auto tcpClient = findTcpClient(client);
        if (tcpClient && tcpClient->message_cb_) {
            tcpClient->message_cb_(tcpClient, buf->base, nread);
        }
    } else {
        if (nread < 0) {
            if (nread != UV_EOF) {
                fprintf(stderr, "Read error %s\n", uv_err_name(nread));
            }
            auto tcpClient = findTcpClient(client);
            if (tcpClient) {
                tcpClient->close();
                tcpClient->setConnectionStatus(ConnectionStatus::kDisConnected);
            }
        }
        free(buf->base);
    }
}

UvTcpClientPtr UvTcpClient::findTcpClient(uv_stream_s *handle) {
    int sockFd = kInvalidSocket;
    assert(uv_fileno((uv_handle_t *)handle, &sockFd) == 0);

    if (g_conn_map.find(sockFd) != g_conn_map.end()) {
        return g_conn_map[sockFd];
    } else {
        cout << "not find fd=" << sockFd << endl;
    }
    return nullptr;
}

void UvTcpClient::runLoopInThread() {
    if (!g_is_thread_loop_init_) {
        g_is_thread_loop_init_ = true;

        g_timer_ = (uv_timer_s *)malloc(sizeof(uv_timer_s));
        uv_timer_init(uv_default_loop(), g_timer_);
        uv_timer_start(g_timer_, onTimer, 0, 1000);
        std::thread t([&]() {
            auto loop = uv_default_loop();
            uv_run(loop, UV_RUN_DEFAULT);
            cout << "uv loop is success stop" << endl;
        });
        t.detach();
    }
}

void UvTcpClient::stopLoop() {
    for (auto &item : g_conn_map) {
        item.second->close();
    }

    uv_timer_stop(g_timer_);
    free(g_timer_);

    uv_stop(uv_default_loop());
}