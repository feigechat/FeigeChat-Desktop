cmake_minimum_required(VERSION 3.14)

project(mac)

add_definitions(
        -g
        -fPIC
        -D__STDC_FORMAT_MACROS
        -Wall
        -Wno-unused-parameter
        -Wno-unused-function
        -Wno-unused-const-variable
        -Wno-unused-variable
        -Wno-unused-value
        -Wshadow
        -Wcast-qual
        -Wcast-align
        -Wwrite-strings
        -Wsign-compare
        -Winvalid-pch
        -fms-extensions
        -Wfloat-equal
        -Wextra
        -std=c++14
        #-Werror # 警告视为错误，比较严格，可以根据需求启用
)

# feigeChat 通过该标志判断是否在Qt Creator中打开
set(IN_CLION_IDE true CACHE INTERNAL "is in clion ide")

# 公共第三方依赖
set(THIRD_LIB_DIR
        ${PROJECT_SOURCE_DIR}/3rd-party/lib
        ${PROJECT_SOURCE_DIR}/3rd-party/lib/lib         # protobuf
        )
set(THIRD_INCLUDE_DIR
        ${PROJECT_SOURCE_DIR}/3rd-party/spdlog-1.9.2/include
        ${PROJECT_SOURCE_DIR}/3rd-party/libuv-1.44.1/include
        ${PROJECT_SOURCE_DIR}/3rd-party/lib/include/            # protobuf
        ${PROJECT_SOURCE_DIR}/3rd-party/SQLiteCpp-3.1.1/include # SQLiteCPP
        )

# 库
add_subdirectory(chatkit)
add_subdirectory(feigechat)

# 生成demo
set(BUILD_DEMO true)
if (BUILD_DEMO)
    add_subdirectory(test/client)
    add_subdirectory(test/libuvdemo)
    add_subdirectory(test/unit_test)
endif ()