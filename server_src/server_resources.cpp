#include "server_resources.hpp"

Resource::Resource() {}

std::string Resource::operator()(std::string const &resource) {
	Lock lock(this->mutex);
	if (this->resources.find(resource) != resources.end()) {
		return this->resources[resource];
	}
	return "";
}

void Resource::store(std::string const &key, std::string const &value) {
	Lock lock(this->mutex);
	this->resources[key] = value;
}

Resource::~Resource() {}
