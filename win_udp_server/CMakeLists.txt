cmake_minimum_required(VERSION 3.0)

file(GLOB sources "sources/*.cpp")
file(GLOB headers "headers/*.h")

add_executable(win_udp_server ${sources} ${headers})
