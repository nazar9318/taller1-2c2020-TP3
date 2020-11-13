#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Protocol {
    private:
        //Función: devuelve la palabra en la posición p de message
        static std::string advanceIn(std::string const &message, size_t p);
        
    public:
        //Constructor estándar
        Protocol();

        //Función: devuelve el método del petitorio
        static std::string getMethod(std::string const &message);

        //Función: devuelve el recurso del petitorio
        static std::string getResource(std::string const &message);

        //Función: devuelve el protocol del petitorio
        static std::string getProtocol(std::string const &message);

        //Función: devuelve el body del petitorio
        static std::string getBody(std::string const &message);

        //Función: devuelve el body del archivo de entrada
        static std::string getBodyFile(std::string const &file_name);
        
        //Destructor estándar
        ~Protocol();
};

#endif
