#include "ChatroomConfig.hpp"
#include <iostream>
#include "Server.hpp"

int main(int argc, char* argv[]) {
    if (argv[1] == "-version" || argv[1] == "-v") {
        std::cout << "Chatroom Version " << Chatroom_VERSION_MAJOR << "." << ChatroomVERSION_MINOR << endl;
        return 0;
    }
    return 0;
}