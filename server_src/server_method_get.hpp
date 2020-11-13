#ifndef SERVER_METHOD_GET_H
#define SERVER_METHOD_GET_H

#include <map>
#include <string>
#include "server_method.hpp"
#include "server_protocol.hpp"
#include "server_resources.hpp"

class MethodGet : public Method {
    public:
        //Constructor: recibe una referencia al repositorio de recursos
        explicit MethodGet(Resource &resources);

        //Función: devuelve la respuesta correspondiente al método GET
        std::string respond(std::string const &message) override;
        
        //Destructor estándar
        ~MethodGet();
};

#endif
