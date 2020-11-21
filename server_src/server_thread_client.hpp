#ifndef SERVER_THREAD_CLIENT_H
#define SERVER_THREAD_CLIENT_H

#include <map>
#include <atomic>
#include <vector>
#include <string>
#include "server_parser.hpp"
#include "server_response.hpp"
#include "server_resources.hpp"
#include "server_impressor.hpp"
#include "../common_src/common_socket.hpp"
#include "../common_src/common_thread.hpp"

class ThreadClient : public Thread {
    private:
        Socket peer;
        Resource &resources;
        std::atomic<bool> is_running;
        std::string receiveFromClient();
        void sendToClient(std::string const& message);
    public:
        //Función: recibe las referencias al peer con
        //el que se comunica y al repositorio de recursos
        ThreadClient(Socket &&peer, Resource &resources);
        
        //Función: lee el mensaje recibido por el peer
        //y le envía la respuesta al mismo
        void run() override;
        
        //Función: cierra el socket peer
        void stop();

        bool running() const;
        
        //Función: libera recursos
        virtual ~ThreadClient();
};

#endif
