#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Protocol {
    private:
        static std::string advanceIn(std::string const &message, size_t p);
    public:
        Protocol();

        static std::string getMethod(std::string const &message);

        static std::string getResource(std::string const &message);

        static std::string getProtocol(std::string const &message);

        static std::string getBody(std::string const &message);

        static std::string getBodyFile(std::string const &file_name);
        
        ~Protocol();
};

#endif
