#include "server_resources.hpp"

Resource::Resource() {}

std::string Resource::operator()(std::string const &resource) {
	if (this->resources.find(resource) != resources.end()) {
		return this->resources[resource];
	}
	return "";
}

void Resource::store(std::string const &key, std::string const &value) {
	this->resources[key] = value;
}

Resource::~Resource() {}
