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
        //Función: crea el socket servidor e
        //inicializa el repositorio de los recursos
        ServerUser(int argc, char* argv[]);

        //Función: ejecuta el flujo del programa,
        //hasta que el usuario ingresa 'q'
        void ejecutar();
        
        //Función: libera recursos
        ~ServerUser();
};

#endif
