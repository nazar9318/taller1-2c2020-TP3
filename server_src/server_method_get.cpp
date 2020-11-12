#include "server_method_get.hpp"

MethodGet::MethodGet(Resource &resources)
: Method(resources) {}

std::string MethodGet::respond(std::string const &message) {
	std::string resource = Protocol::getResource(message);
	std::string protocol = Protocol::getProtocol(message);
	if (resource.compare("/") == 0) {
		std::string result = " 200 OK\nContent-Type: text/html\n\n";
		return protocol + result + this->resources("root");
	} else if (this->resources(resource) != "") {
		std::string result = " 200 OK\nContent-Type: text/html\n\n";
		return protocol + result + this->resources(resource);
	} else {
		return protocol + " 404 NOT FOUND\n\n";
	}
}

MethodGet::~MethodGet() {}
