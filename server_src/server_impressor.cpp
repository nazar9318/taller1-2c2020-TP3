#include "server_impressor.hpp"

Impressor::Impressor() {}

void Impressor::operator()(std::string const &message) const {
	std::stringstream stream_message(message);
	std::string out;
	getline(stream_message, out);
	std::cout << out << std::endl;
}

Impressor::~Impressor() {}
