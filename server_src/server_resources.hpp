#ifndef SERVER_RESOURCE_H
#define SERVER_RESOURCE_H

#include <map>
#include <mutex>
#include <string>
#include <fstream>
#include <iostream>
#include "server_lock.hpp"

class Resource {
    private:
        std::mutex mutex;
        std::map<std::string, std::string> resources;
    public:
        //Constructor estándar
        Resource();

        //Devuelve el recurso de la clave key
        std::string operator()(std::string const &key);
        
        void store(std::string const &key, std::string const &value);

        //Destructor estándar
        ~Resource();
};

#endif
