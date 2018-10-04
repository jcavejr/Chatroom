#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <sstream>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

#include "ChatroomConfig.hpp"
#include "User.hpp"
#include "Server.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Must supply at least one argument" << std::endl;
        exit(1);
    }
    std::string sargv[argc];
    for (int i = 0; i < argc; i++) {
        sargv[i] = argv[i];
    }
    if (sargv[1] == "-version" || sargv[1] == "-v") {
        std::cout << "Chatroom Version " << Chatroom_VERSION_MAJOR << "." << Chatroom_VERSION_MINOR << std::endl;
        return 0;
    }
    int requestedPort;
    std::istringstream stringStream(argv[1]);
    if (!(stringStream >> requestedPort)) {
        std::cerr << "Error: Must supply a port number to start the socket" << std::endl;
        exit(1);
    }
    
    Server myServer(requestedPort);
    return 0;
}