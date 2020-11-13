#ifndef SERVER_RESPONSE_H
#define SERVER_RESPONSE_H

#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "server_resources.hpp"
#include "server_method.hpp"
#include "server_method_get.hpp"
#include "server_method_post.hpp"

class Response {
    protected:
        Resource &resources;
        Response() = default;
    public:
        //Constructor: recibe una referencia al repositorio de recursos
        explicit Response(Resource &resources);

        //Función: devuelve la respuesta al petitorio según sea POST o GET,
        //en otro caso indica que se pasó un método no válido
        std::string operator()(std::string const &message);

        //Destructor estándar
        virtual ~Response();
};

#endif

