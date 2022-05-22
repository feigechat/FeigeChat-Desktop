/** @file tcp_server.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/20
 */

#ifndef MAC_TCP_SERVER_H_
#define MAC_TCP_SERVER_H_

#include <atomic>
#include <string>

/** @class tcp_server
 * @brief
 */
class UvTcpServer {
public:
    UvTcpServer(const UvTcpServer &) = delete;

    UvTcpServer(const UvTcpServer &&) = delete;

    UvTcpServer operator=(const UvTcpServer &) = delete;

    static UvTcpServer *getInstance();

public:
    void run(int listen_port);

    void stop();

private:
    void threadProc();

private:
    UvTcpServer() : run_(true) {}
    ~UvTcpServer() = default;

private:
    int listen_fd_;
    std::atomic_bool run_;
};

#endif // MAC_TCP_SERVER_H_
