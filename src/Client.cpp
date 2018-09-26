#include "ChatroomConfig.hpp"
#include "Client.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argv[1] == "-version" || argv[1] == "-v") {
        std::cout << "Chatroom Version " << Chatroom_VERSION_MAJOR << "." << ChatroomVERSION_MINOR << endl;
        return 0;
    }
    return 0;
}