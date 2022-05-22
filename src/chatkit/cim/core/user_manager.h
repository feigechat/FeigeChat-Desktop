/** @file im_user_manager.h
 * @brief im_user_manager
 * @author xmcy0011@sina.com
 * @date 2021/1/15
 */

#ifndef _IM_USER_MANAGER_F51B4D37_8EE2_425D_8E93_7AD84E14CA08_
#define _IM_USER_MANAGER_F51B4D37_8EE2_425D_8E93_7AD84E14CA08_

#include "cim/base/noncopyable.h"
#include "cim/cim_def.h"
#include "cim/cim_dll.h"

namespace cim {
namespace core {

struct HttpResponseBase {
    int code;
    std::string msg;
};

class CIM_DLL_API UserManager : cim::base::noncopyable {
public:
    static UserManager* getInstance();

public:
    /**
     * 注册一个用户
     * @param userName：用户名
     * @param userPwd：密码（明文），内部会进行加密
     * @param nickName: 昵称
     * @param out: 失败具体的错误码，out.code 和
     * @return 成功与否
     */
    bool registerUser(std::string userName, std::string userPwd, std::string nickName, HttpResponseBase& out);

    /**
     * 随机获取一个用户昵称
     * @param random_nick: 用户昵称
     * @param out: 结果
     * @return
     */
    bool generateNickName(std::string& random_nick, HttpResponseBase& out);

private:
    UserManager();
    ~UserManager() override = default;
};

} // namespace core
} // namespace cim

#endif //_IM_USER_MANAGER_F51B4D37_8EE2_425D_8E93_7AD84E14CA08_