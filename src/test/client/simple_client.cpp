/** @file main.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/16
 */

#include <iostream>
#include <thread>

using namespace std;

#include "cim/cim.h"

void wait_exit(int no) { cim::cleanup(); }

void loginResult(const CIM::Login::CIMAuthRsp& rsp) {
    cout << "login result:" << rsp.result_code() << ",result_string:" << rsp.result_string() << endl;
}

void loginTimeout() {}

int main() {
    signal(SIGINT, wait_exit);

    cout << "hello world" << endl;

    // must init
    cim::ChatKitConfig config;
    config.serverInfo.ip = "127.0.0.1";
    cim::initChatKit(config);

    cim::core::Client::getInstance()->login("gaozz", "123456", loginResult, loginTimeout);

    std::this_thread::sleep_for(std::chrono::seconds(60));
    return 0;
}