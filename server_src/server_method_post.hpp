#ifndef SERVER_METHOD_POST_H
#define SERVER_METHOD_POST_H

#include <map>
#include <string>
#include "server_method.hpp"
#include "server_protocol.hpp"
#include "server_resources.hpp"

class MethodPost : public Method {
    public:
        //Constructor: recibe una referencia al repositorio de recursos
        explicit MethodPost(Resource &resources);

        //Función: devuelve la respuesta correspondiente al método POST
        std::string respond(std::string const &message) override;
        
        //Destructor estándar
        ~MethodPost();
};

#endif

