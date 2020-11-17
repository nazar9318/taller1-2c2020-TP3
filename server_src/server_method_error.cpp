#include "server_method_error.hpp"

MethodError::MethodError(Resource &resources)
: Method(resources) {}

std::string MethodError::respond(std::string const &message) {
	std::stringstream response;
    response << "HTTP 405 METHOD NOT ALLOWED\n\n";
    response << Parser::getMethod(message);
    response << " es un comando desconocido\n";
    return response.str();
}

MethodError::~MethodError() {}
