#include "server_response.hpp"

Response::Response(Resource &resources) :
resources(resources) {}

std::string Response::operator()(std::string const &message) {
    std::cout << Parser::getMethod(message);
    std::cout << " " + Parser::getResource(message);
    std::cout << " " + Parser::getProtocol(message) << std::endl;
    if (Parser::getMethod(message) == "GET") {
        MethodGet get(this->resources);
        return get.respond(message);
    } else if (Parser::getMethod(message) == "POST") {
        MethodPost post(this->resources);
        return post.respond(message);
    }
    std::string format = "HTTP 405 METHOD NOT ALLOWED\n\n";
    std::string unknown = " es un comando desconocido\n";
    return format + Parser::getMethod(message) + unknown;
}

Response::~Response() {}
