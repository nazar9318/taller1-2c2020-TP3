#include "server_method_post.hpp"

MethodPost::MethodPost(Resource &resources)
: Method(resources) {}

std::string MethodPost::respond(std::string const &message) {
    std::string resource = Protocol::getResource(message);
    if (resource.compare("/") == 0) {
        std::string protocol = Protocol::getProtocol(message);
        return "HTTP 403 FORBIDDEN\n\n";
    } else {
        this->resources.store(resource, Protocol::getBody(message));
        std::string protocol = Protocol::getProtocol(message);
        std::string result = " 200 OK\n\n";
        return protocol + result + this->resources(resource);
    }
}

MethodPost::~MethodPost() {}
