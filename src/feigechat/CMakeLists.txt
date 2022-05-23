cmake_minimum_required(VERSION 3.14)

project(feigechat)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 版本号设置
set(PROJECT_VERSION 1.0)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)

# The Qt SDK path
set(QT_SDK_DIR "/Users/xuyc/share/Qt/6.2.4/macos/")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_SDK_DIR})

# 在QT Creator中找不到，需要手动include
if (IN_CLION_IDE)

else()
    message("current in qt creator")

    # 公共第三方依赖
    set(THIRD_LIB_DIR
            ../3rd-party/lib
            ../3rd-party/lib/lib         # protobuf
            )
    set(THIRD_INCLUDE_DIR
            ../3rd-party/spdlog-1.9.2/include
            ../3rd-party/libuv-1.44.1/include
            ../3rd-party/lib/include/            # protobuf
            ../3rd-party/SQLiteCpp-3.1.1/include # SQLiteCPP
            )

    # im sdk
    set(CHATKIT_INCLUDE_DIR ../chatkit)
    set(CHATKIT_LIB_DIR ../cmake-build-debug/chatkit)

    # im sdk
    include_directories(${CHATKIT_INCLUDE_DIR} ${THIRD_INCLUDE_DIR})
    link_directories(${CHATKIT_LIB_DIR} ${THIRD_LIB_DIR})
endif ()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        resource.qrc
        gui/mainwindow.cpp
        gui/mainwindow.h
        gui/mainwindow.ui
        gui/logindialog.h
        gui/logindialog.cpp
        gui/logindialog.ui
        gui/server_setting_dialog.h
        gui/server_setting_dialog.cpp
        gui/server_setting_dialog.ui
        gui/user_register_dialog.h
        gui/user_register_dialog.cpp
        gui/user_register_dialog.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(feigechat
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET feigechat APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(feigechat SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(feigechat
            ${PROJECT_SOURCES}
        )
    endif()
endif()

if (IN_CLION_IDE)
    target_link_libraries(feigechat PRIVATE Qt${QT_VERSION_MAJOR}::Widgets cim::chatkit protobuf::libprotobuf-lite)
else()
    target_link_libraries(feigechat PRIVATE Qt${QT_VERSION_MAJOR}::Widgets chatkit libprotobuf-lite.a)
endif()

set_target_properties(feigechat PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER cim.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(feigechat)
endif()
