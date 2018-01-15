cmake_minimum_required(VERSION 3.0)
project(cCppGolden)

include_directories(
include_common
)

add_subdirectory(win_udp_client)
add_subdirectory(win_udp_server)
add_subdirectory(windowsService)