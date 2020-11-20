#include "server_method_post.hpp"

MethodPost::MethodPost(Resource &resources)
: Method(resources) {}

std::string MethodPost::respond(std::string const &message) {
	std::stringstream answer;
	std::string resource = Parser::getResource(message);
	answer << Parser::getProtocol(message);
	if (resource.compare("/") != 0) {
		this->resources.store(resource, Parser::getBody(message));
		answer << " 200 OK\n\n";
		answer << this->resources(resource);
		return answer.str();
	}
	answer << " 403 FORBIDDEN\n\n";
	return answer.str();
}

MethodPost::~MethodPost() {}

