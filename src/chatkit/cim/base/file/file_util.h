/** @file file_util.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/16
 */

#ifndef CIMSDK_FILE_UTIL_H_
#define CIMSDK_FILE_UTIL_H_

#include <list>
#include <string>

#include "cim/cim_dll.h"

namespace cim {
namespace base {

#if defined(OS_WIN)
typedef std::wstring PathString;
#else
typedef std::string PathString;
#endif

typedef PathString::value_type PathChar;

// Check the filepath is exist
// If |is_directory| is true, check a directory, or check the path
CIM_DLL_API bool FilePathIsExist(const PathString &filepath_in, bool is_directory);

// Create a directory, all subdirs will be created if not existing
CIM_DLL_API bool CreateDirectory(const PathString &full_path);

CIM_DLL_API bool CreateDirectory(const char *full_path);

// Parse and extract all components of a path
CIM_DLL_API bool ParsePathComponents(const PathChar *PathChar, std::list<PathString> &components);

} // namespace base
} // namespace cim

#endif // CIMSDK_FILE_UTIL_H_
