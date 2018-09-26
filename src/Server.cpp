#include "ChatroomConfig.hpp"
#include <iostream>
#include "Server.hpp"
#include <string>

int main(int argc, char* argv[]) {
    std::string sargv[argc];
    for (int i = 0; i < argc; i++) {
        sargv[i] = argv[i];
    }
    if (sargv[1] == "-version" || sargv[1] == "-v") {
        std::cout << "Chatroom Version " << Chatroom_VERSION_MAJOR << "." << Chatroom_VERSION_MINOR << std::endl;
        return 0;
    } else {
        std::cerr << "Error: Invalid invocation of Server" << std::endl;
        return 1;
    }
    return 0;
}