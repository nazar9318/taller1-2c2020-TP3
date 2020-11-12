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
        explicit Response(Resource &resources);

        std::string operator()(std::string const &message);
        
        virtual ~Response();
};

#endif

