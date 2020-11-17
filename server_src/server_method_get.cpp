#include "server_method_get.hpp"

MethodGet::MethodGet(Resource &resources)
: Method(resources) {}

std::string MethodGet::respond(std::string const &message) {
	std::stringstream answer;
	answer << Parser::getProtocol(message);
	std::string resource = Parser::getResource(message);
	if (resource.compare("/") == 0) {
		answer << " 200 OK\nContent-Type: text/html\n\n";
		answer << this->resources("root");
		return answer.str();
	} else if (this->resources(resource) != "") {
		answer << Parser::getProtocol(message);
		answer << " 200 OK\nContent-Type: text/html\n\n";
		answer << this->resources(resource);
		return answer.str();
	}
	answer << " 404 NOT FOUND\n\n";
	return answer.str();
}

MethodGet::~MethodGet() {}
