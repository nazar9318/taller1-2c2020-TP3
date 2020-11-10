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
        explicit Method(Resource &resources);

        virtual std::string respond(std::string const &message) = 0;
        
        virtual ~Method();
};

#endif

