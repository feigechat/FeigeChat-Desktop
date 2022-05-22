/** @file string_util.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/16
 */

#ifndef HELLOCHAT_STRING_UTIL_H
#define HELLOCHAT_STRING_UTIL_H

#include <string>

namespace cim {
namespace base {

/** @fn s2ws
 * @brief utf8 string convert to wstring
 * @param [in]str: utf8 string
 * @return utf8 wstring
 */
std::wstring UTF8ToUTF16(const std::string &str);

/** @fn ws2s
 * @brief utf8 wstring convert to string
 * @param [in]str: utf8 wstring
 * @return utf8 string
 */
std::string ws2s(const std::wstring &w_str);

} // namespace base
} // namespace cim

#endif // HELLOCHAT_STRING_UTIL_H
