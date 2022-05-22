/** @file user_manager_test.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/22
 */

#include "cim/cim.h"
#include "gtest/gtest.h"

using namespace cim::core;

#include <iostream>

// 注册用户单元测试
TEST(UserManager, registerUser) {
    HttpResponseBase res;
    ASSERT_TRUE(UserManager::getInstance()->registerUser("gaozz", "123456", "高真真", res));
}

// 随机生成一个用户昵称单元测试
TEST(UserManager, generateNickName) {
    HttpResponseBase res;
    std::string nick;
    ASSERT_TRUE(UserManager::getInstance()->generateNickName(nick, res));
    std::cout << "generate nickName = " << nick << std::endl;
}