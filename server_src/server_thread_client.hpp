#ifndef SERVER_THREAD_CLIENT_H
#define SERVER_THREAD_CLIENT_H

#include <map>
#include <atomic>
#include <vector>
#include <string>
#include "server_protocol.hpp"
#include "server_response.hpp"
#include "server_resources.hpp"
#include "../common_src/common_socket.hpp"
#include "../common_src/common_thread.hpp"

class ThreadClient : public Thread {
    private:
        Socket &peer;
        Resource &resources;
        //std::atomic<bool> keep_talking;
        std::string setResponse(std::string const &message);
    public:
        ThreadClient(Socket &&peer, Resource &resources);
        void run() override;
        void closeCommunication();
        void stop();
        virtual ~ThreadClient();
};

#endif
