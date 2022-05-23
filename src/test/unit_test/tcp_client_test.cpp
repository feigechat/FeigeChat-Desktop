/** @file tcp_client_test.h
 * @brief
 * @author teng.qing
 * @date 2022/5/22
 */
#include "cim/cim.h"
#include "gtest/gtest.h"

using namespace cim::base;

TEST(TcpClient, connect) {
    cim::base::EventLoop::runInThread(); // must run before connect

    cim::base::TcpClientPtr client = std::make_shared<cim::base::TcpClient>();
    client->setConnectionCallback([client](const cim::base::TcpClientPtr &, cim::base::ConnectionStatus status) {
        std::cout << "ConnectionCallback: connect status change to " << (int)status << std::endl;

        std::string str = "hello";
        client->send(str.c_str(), str.length());
    });
    client->setMessageCallback([](const TcpClientPtr &, const char *buf, int len) {
        std::cout << "MessageCallback: " << std::string(buf, len) << std::endl;
    });

    client->connect("127.0.0.1", 8000);

    std::this_thread::sleep_for(std::chrono::seconds(10));
    client->close();
    cim::base::EventLoop::stop();
}
