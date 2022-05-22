/** @file libuv_tcp_client.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/20
 */

#ifndef MAC_LIBUV_TCP_CLIENT_H_
#define MAC_LIBUV_TCP_CLIENT_H_

#include <memory>
#include <string>

#include "cim/base/buffer.h"
#include "cim/base/noncopyable.h"
#include "cim/cim_dll.h"

struct uv_tcp_s;
struct uv_connect_s;
struct uv_write_s;
struct uv_buf_t;
struct uv_timer_s;
struct uv_stream_s;

namespace cim {
namespace base {

enum class ConnectionStatus {
    kDefault,
    kConnecting,
    kDisConnected,
    kConnectOk,
};

class TcpClient;

typedef std::shared_ptr<TcpClient> TcpClientPtr;
typedef std::function<void(const TcpClientPtr &, ConnectionStatus status)> ConnectionCallback;
typedef std::function<void(const TcpClientPtr &, const char *buf, int len)> MessageCallback;

//#define USE_UV_SEND

/** @class TcpClient
 * @brief 封装LibUV，实现tcp client
 * usage:
    cim::base::EventLoop::runInThread(); // must run before connect

    cim::base::TcpClientPtr client = std::make_shared<cim::base::TcpClient>();
    client->setConnectionCallback([](const cim::base::TcpClientPtr &, cim::base::ConnectionStatus status) {
        std::cout << "ConnectionCallback: connect status change to " << (int)status << std::endl;
    });
    client->setMessageCallback([](const cim::base::TcpClientPtr &, char *buf, int len) {
        std::cout << "MessageCallback: " << std::string(buf, len) << std::endl;
    });

    std::string str = "hello";
    client->send(str.c_str(), str.length());
    std::this_thread::sleep_for(std::chrono::seconds(1));
    client->close();

    cim::base::EventLoop::stop();
 */
class CIM_DLL_API TcpClient : public std::enable_shared_from_this<TcpClient>, public cim::base::noncopyable {
public:
    /**
     * 构造
     */
    TcpClient();

    /**
     * 析构
     */
    ~TcpClient() override;

    /**
     * 连接远程服务器，结果通过ConnectionCallback回调
     * @param serverIp：服务器IP
     * @param port：端口
     * @return true: success, false: error
     */
    bool connect(const std::string &serverIp, uint16_t port);

    /**
     * 关闭连接
     */
    void close();

    /**
     * 发送
     * @param buff: 缓冲区
     * @param len: 发送的长度
     * @return >0：发送的数据，=0，对端关闭连接，<0：error
     */
    int send(const char *buff, int len);

    /**
     * 设置连接状态改变回调
     * @param cb: 回调
     */
    void setConnectionCallback(const ConnectionCallback &cb);

    /**
     * 设置收到数据回调
     * @param cb: 回调
     */
    void setMessageCallback(const MessageCallback &cb);

    /**
     * 获取远端端点，IP:Port
     * @return
     */
    std::string remoteAddr() const;

    /**
     * 获取TCP连接状态
     * @return
     */
    ConnectionStatus connectionStatus() const { return connect_status_; }

    /**
     * 检测服务器是可连接（TCP）
     * @param serverIp: ip地址
     * @param port: 端口
     * @return
     */
    static bool ping(const std::string &serverIp, uint16_t port);

private:
    void setConnectionStatus(ConnectionStatus status);

    void onTimer();

private:
    static void onConnect(uv_connect_s *req, int status);

#ifdef USE_UV_SEND
    static void onWrite(uv_write_s *req, int status);
#endif

    static void onRead(uv_stream_s *client, ssize_t nread, const uv_buf_t *buf);

    static TcpClientPtr findTcpClient(uv_stream_s *handle);

private:
    uv_tcp_s *tcp_handle_;
    int sock_fd_; // socket 句柄

    ConnectionStatus connect_status_; // 连接状态

    ConnectionCallback connection_cb_;
    MessageCallback message_cb_;

    std::string server_ip_;
    int16_t server_port_;
};

} // namespace base
} // namespace cim

#endif // MAC_LIBUV_TCP_CLIENT_H_
