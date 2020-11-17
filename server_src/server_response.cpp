#include "server_response.hpp"

Response::Response(Resource &resources) :
resources(resources) {}

std::string Response::operator()(std::string const &message) {
    if (Parser::getMethod(message) == "GET") {
        MethodGet get(this->resources);
        return get.respond(message);
    } else if (Parser::getMethod(message) == "POST") {
        MethodPost post(this->resources);
        return post.respond(message);
    }
    MethodError error(this->resources);
    return error.respond(message);
}

Response::~Response() {}
