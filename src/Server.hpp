#ifndef Server_H
#define Server_H
#include <vector>
#define MAX_PORT_NUMBER 65535
#define MAX_PENDING_CLIENTS 1

class Server {
    private:
        std::vector<User> users;
        int port;
        int openConnection(void);
        std::mutex lock;
    public:
        Server(int inputPort);
        int getPort(void);
};

#endif /* Server_H */