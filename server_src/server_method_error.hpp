#ifndef SERVER_METHOD_ERROR_H
#define SERVER_METHOD_ERROR_H

#include <map>
#include <string>
#include "server_method.hpp"
#include "server_parser.hpp"
#include "server_resources.hpp"

class MethodError : public Method {
    public:
        //Constructor: recibe una referencia al repositorio de recursos
        explicit MethodError(Resource &resources);

        MethodError();

        //Función: devuelve la respuesta correspondiente al método GET
        std::string respond(std::string const &message) override;
        
        //Destructor estándar
        ~MethodError();
};

#endif
