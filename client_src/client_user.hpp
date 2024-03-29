#ifndef CLIENT_USER_H
#define CLIENT_USER_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "../common_src/common_socket.hpp"
#include "../common_src/common_thread.hpp"

class ClientUser : public Thread {
    private:
        Socket client;
        void run() override;
        void sendToServer();
        void receiveFromServer();
    public:
        ClientUser(int argc, char* argv[]);

        void ejecutar();
        
        ~ClientUser();
};

#endif
