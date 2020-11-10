#ifndef SERVER_USER_H
#define SERVER_USER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "server_protocol.hpp"
#include "server_resources.hpp"
#include "server_thread_client.hpp"
#include "server_thread_accepter.hpp"

class ServerUser {
    private:
        Socket server;
        Resource resources;
        std::vector<ThreadClient*> accepted;
    public:
        ServerUser(int argc, char* argv[]);

        void ejecutar();
        
        ~ServerUser();
};

#endif
