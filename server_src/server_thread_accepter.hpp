#ifndef SERVER_THREAD_ACCEPTER_H
#define SERVER_THREAD_ACCEPTER_H

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include "server_resources.hpp"
#include "server_thread_client.hpp"
#include "../common_src/common_socket.hpp"
#include "../common_src/common_thread.hpp"

class ThreadAccepter : public Thread {
    private:
        Socket &server;
        Resource &resources;
        std::vector<ThreadClient*> accepted;
        bool keep_accepting;
    public:
        ThreadAccepter(Socket &server, Resource &resources);

        void run() override;

        void stop();
        
        ~ThreadAccepter();
};

#endif
