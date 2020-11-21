#include "server_resources.hpp"

Resource::Resource() {}

std::string Resource::operator[](std::string const &key) {
	Lock lock(this->mutex);
	if (this->resources.find(key) != resources.end()) {
		return this->resources[key];
	}
	return "";
}

void Resource::store(std::string const &key, std::string const &value) {
	Lock lock(this->mutex);
	this->resources[key] = value;
}

Resource::~Resource() {}
