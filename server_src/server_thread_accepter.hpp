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
        void stopClients();
    public:
        //Constructor: recibe una referencia al
        //servidor y otra al repositorio de recursos
        ThreadAccepter(Socket &server, Resource &resources);

        //Función: hasta que se invoque al método stop, acepta
        //los clientes que quieren comunicarse con el servidor
        void run() override;

        //Función: ThreadAcceptar deja de recibir clientes
        void stop();
        
        //Destructor estándar
        ~ThreadAccepter();
};

#endif
