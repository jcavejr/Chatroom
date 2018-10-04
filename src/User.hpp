#ifndef User_H
#define User_H

class User {
    private:
        bool connected;
        int fileDescriptor;
        int userId;
        void clientSessionThread(void);
    public:
        User(int id, int fd);
        int startThread();
};

#endif /* User_H */