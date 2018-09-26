cmake_minimum_required(VERSION 2.6)
project(Chatroom)

set (Chatroom_VERSION_MAJOR 0)
set (Chatroom_VERSION_MINOR 1)

configure_file (
    "src/ChatroomConfig.hpp.in"
    "bin/ChatroomConfig.hpp"
)

include_directories("bin")

add_executable(bin/Client src/Client.cpp)
add_executable(bin/Server src/Server.cpp)