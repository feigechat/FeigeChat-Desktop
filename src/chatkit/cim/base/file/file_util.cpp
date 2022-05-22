/** @file file_util.h
 * @brief
 * @author xmcy0011@sina.com
 * @date 2021/7/16
 */

#include "file_util.h"

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string>
#include <vector>

namespace cim {
namespace base {

const PathChar kFilePathSeparators[] = "/";

bool FilePathIsExist(const PathString &filepath_in, bool is_directory) {
    if (!is_directory)
        return access(filepath_in.c_str(), F_OK) == 0;
    else {
        DIR *directory = opendir(filepath_in.c_str());
        if (directory != nullptr) {
            closedir(directory);
            return true;
        }
    }
    return false;
}

bool CreateDirectory(const PathString &full_path) { return CreateDirectory(full_path.c_str()); }

bool CreateDirectory(const char *full_path) {
    if (full_path == nullptr) return false;

    std::list<std::string> subpaths;
    ParsePathComponents(full_path, subpaths);
    if (subpaths.empty()) return false;

    // Collect a list of all parent directories.
    auto curr = subpaths.begin();
    for (auto prev = curr++; curr != subpaths.end(); curr++) {
        *curr = *prev + *curr;
        prev = curr;
    }

    // Iterate through the parents and create the missing ones.
    for (auto i = subpaths.begin(); i != subpaths.end(); ++i) {
        if (FilePathIsExist(i->c_str(), true)) continue;
        if (mkdir(i->c_str(), 0700) == 0) continue;
        // Mkdir failed, but it might have failed with EEXIST, or some other
        // error due to the the directory appearing out of thin air. This can
        // occur if two processes are trying to create the same file system tree
        // at the same time. Check to see if it exists and make sure it is a
        // directory.
        if (!FilePathIsExist(i->c_str(), true)) return false;
    }
    return true;
}

template <typename CharType>
bool ParsePathComponentsT(const CharType *path, const CharType *seperators,
                          std::list<std::basic_string<CharType> > &components) {
    components.clear();
    if (path == NULL) return false;
    const CharType *prev = NULL;
    const CharType *next = path;
    const CharType *c;
    while (*next) {
        prev = next;
        // find the first seperator
        for (;;) {
            for (c = seperators; *c && *next != *c; c++)
                ;
            if (*c || !*next) break;
            next++;
        }
        components.push_back(std::basic_string<CharType>(prev, next - prev));
        if (*next) components.back().push_back(*seperators);
        // skip duplicated seperators
        for (++next;;) {
            for (c = seperators; *c && *next != *c; c++)
                ;
            if (!*c) break;
            next++;
        }
    }
    return true;
}

bool ParsePathComponents(const PathChar *path, std::list<PathString> &components) {
    return ParsePathComponentsT<PathChar>(path, kFilePathSeparators, components);
}

} // namespace base
} // namespace cim
