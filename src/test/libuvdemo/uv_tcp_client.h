/** @file libuv_tcp_client.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/20
 */

#ifndef MAC_LIBUV_TCP_CLIENT_H_
#define MAC_LIBUV_TCP_CLIENT_H_

#include <memory>
#include <string>

struct uv_tcp_s;
struct uv_connect_s;
struct uv_write_s;
struct uv_buf_t;
struct uv_timer_s;
struct uv_stream_s;

enum class ConnectionStatus {
    kDefault,
    kConnecting,
    kDisConnected,
    kConnected,
};

class UvTcpClient;

typedef std::shared_ptr<UvTcpClient> UvTcpClientPtr;
typedef std::function<void(const UvTcpClientPtr &, ConnectionStatus status)> ConnectionCallback;
typedef std::function<void(const UvTcpClientPtr &, char *buf, int len)> MessageCallback;

// #define USE_LIBUV_WRITE // 使用libuv的write函数发送数据

/** @class libuv_tcp_client
 * @brief
 */
class UvTcpClient : public std::enable_shared_from_this<UvTcpClient> {
public:
    UvTcpClient();

    virtual ~UvTcpClient();

    UvTcpClient(const UvTcpClient &) = delete;

    UvTcpClient(const UvTcpClient &&) = delete;

    UvTcpClient operator=(const UvTcpClient &) = delete;

    bool connect(const std::string &serverIp, uint16_t port);

    void close();

    int send(const char *buff, int len);

    void setConnectionCallback(const ConnectionCallback &cb);

    void setMessageCallback(const MessageCallback &cb);

public:
    static void runLoopInThread();

    static void stopLoop();

private:
    void setConnectionStatus(ConnectionStatus status);

    void onTimer();

private:
    static void onTimer(uv_timer_s *timer);

    static void onConnect(uv_connect_s *req, int status);

#ifdef USE_LIBUV_WRITE
    static void onWrite(uv_write_s *req, int status);
#endif

    static void onRead(uv_stream_s *client, ssize_t nread, const uv_buf_t *buf);

    static UvTcpClientPtr findTcpClient(uv_stream_s *handle);

private:
    uv_tcp_s *tcp_handle_;
    int sock_fd_;

    ConnectionStatus connect_status_;
    ConnectionCallback connection_cb_;
    MessageCallback message_cb_;
};

#endif // MAC_LIBUV_TCP_CLIENT_H_
