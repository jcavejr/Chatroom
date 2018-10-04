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

#include "User.hpp"
#include "Server.hpp"


Server::Server(int inputPort) {
    if (inputPort < 0 || inputPort > MAX_PORT_NUMBER) {
        std::cerr << "Error: port >" << inputPort << "< is out of range in file " << __FILE__ << " line " << __LINE__ << std::endl;
    }
    port = inputPort;
    openConnection();
}

int Server::openConnection(void) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error: socket returned -1 in file " << __FILE__ << " line " << __LINE__ << std::endl;
        exit(1);
    }
    struct sockaddr_in serverAddr;
    struct sockaddr_in newClientAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = port;
    socklen_t ic;
    int on = 1;
    if (bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error: bind returned -1 in file " << __FILE__ << " line " << __LINE__ << std::endl;
        exit(1);
    } else if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
        std::cerr << "Error: setsockopt returned -1 in file " << __FILE__ << " line " << __LINE__ << std::endl;
        exit(1);
    } else if (listen(serverSocket, MAX_PENDING_CLIENTS) == -1) {
        std::cerr << "Error: listen returned -1 in file " << __FILE__ << " line " << __LINE__ << std::endl;
        exit(1);
    }
    int newUserFD;
    int newUserID = 0;
    ic = sizeof(newClientAddr);
    while (newUserFD = accept(serverSocket, (struct sockaddr*) &newClientAddr, &ic) != -1) {
        users.push_back(User(newUserID, newUserFD));
    }
    return 0;
}

int Server::getPort(void) {
    return port;
}