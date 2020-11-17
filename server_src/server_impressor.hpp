#ifndef SERVER_IMPRESSOR_H
#define SERVER_IMPRESSOR_H

#include <string>
#include <iostream>
#include "server_parser.hpp"

class Impressor {
    public:
        //Función: constructor de Lock,
        //llama al metodo lock del mutex
        Impressor();

        void operator()(std::string const &message) const;

        //Función: destructor de Lock,
        //llama al metodo unlock del mutex
        ~Impressor();
};

#endif
