#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include "User.hpp"

User::User(int id, int fd) {
    userId = id;
    fileDescriptor = fd;
    startThread();
}

int User::startThread() {
    connected = true;
    std::thread thread(&User::clientSessionThread, this);
    return 0;
}

void User::clientSessionThread(void) {
    char buffer[256];
    while (read(fileDescriptor, buffer, 255) > 0) {
        std::cout << buffer << std::endl;
    }
    connected = false;
}