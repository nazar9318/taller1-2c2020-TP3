#ifndef SERVER_METHOD_GET_H
#define SERVER_METHOD_GET_H

#include <map>
#include <string>
#include "server_method.hpp"
#include "server_protocol.hpp"
#include "server_resources.hpp"

class MethodGet : public Method {
    public:
        explicit MethodGet(Resource &resources);

        std::string respond(std::string const &message) override;
        
        ~MethodGet();
};

#endif
