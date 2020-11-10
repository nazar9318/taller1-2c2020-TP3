#ifndef SERVER_METHOD_POST_H
#define SERVER_METHOD_POST_H

#include <map>
#include <string>
#include "server_method.hpp"
#include "server_protocol.hpp"
#include "server_resources.hpp"

class MethodPost : public Method {
    public:
        explicit MethodPost(Resource &resources);

        std::string respond(std::string const &message) override;
        
        ~MethodPost();
};

#endif

