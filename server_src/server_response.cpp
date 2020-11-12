#include "server_response.hpp"

Response::Response(Resource &resources) :
resources(resources) {}

std::string Response::operator()(std::string const &message) {
        Method *method = NULL;
        MethodGet get(this->resources);
        MethodPost post(this->resources);
        if (Protocol::getMethod(message) == "GET") {
            method = &get;
        } else if (Protocol::getMethod(message) == "POST") {
            method = &post;
        } else {
            std::string format = "HTTP 405 METHOD NOT ALLOWED\n\n";
            std::string unknown = " es un comando desconocido\n";
            return format + Protocol::getMethod(message) + unknown;
        }
        return method->respond(message);
}

Response::~Response() {}
