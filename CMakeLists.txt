cmake_minimum_required(VERSION 3.0)
project(Chatroom C CXX)

set (Chatroom_VERSION_MAJOR 0)
set (Chatroom_VERSION_MINOR 1)

configure_file (
    "src/ChatroomConfig.hpp.in"
    "bin/ChatroomConfig.hpp"
)

include_directories("bin")

add_compile_options(-std=c++11 -lpthread)

add_library(ChatroomObjects SHARED src/User.cpp src/Server.cpp)
add_executable(main src/main.cpp)

FIND_PACKAGE ( Threads REQUIRED )
target_link_libraries(ChatroomObjects ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(main ChatroomObjects)

set_property(TARGET ChatroomObjects PROPERTY LIBRARY_OUTPUT_DIRECTORY lib)
set_property(TARGET main PROPERTY RUNTIME_OUTPUT_DIRECTORY bin)