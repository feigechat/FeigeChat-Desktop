project(libuv_tcp_client)

find_package(unofficial-libuv CONFIG REQUIRED)

add_executable(libuv_tcp_client uv_tcp_client.h uv_tcp_client.cpp client.cpp)

target_link_libraries(libuv_tcp_client unofficial::libuv::libuv pthread)

add_executable(libuv_tcp_server uv_tcp_server.h uv_tcp_server.cpp server.cpp)