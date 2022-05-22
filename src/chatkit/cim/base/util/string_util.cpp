/** @file string_util.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/16
 */

#include "string_util.h"

#include <codecvt>
#include <locale>

namespace cim {
namespace base {

std::wstring UTF8ToUTF16(const std::string &str) {
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.from_bytes(str);
}

std::string ws2s(const std::wstring &wstr) {
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

} // namespace base
} // namespace cim