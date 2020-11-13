#ifndef SERVER_METHOD_H
#define SERVER_METHOD_H

#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "server_resources.hpp"

class Method {
    protected:
        Resource &resources;
        Method() = default;
    public:
        //Constructor: recibe una referencia al repositorio de recursos
        explicit Method(Resource &resources);

        //Función: devuelve la respuesta al petitorio
        virtual std::string respond(std::string const &message) = 0;
        
        //Destructor estándar
        virtual ~Method();
};

#endif

