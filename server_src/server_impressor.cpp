#include "server_impressor.hpp"

Impressor::Impressor() {}

void Impressor::operator()(std::string const &message) const {
	std::stringstream server_out;
	server_out << Parser::getMethod(message);
	server_out << " ";
	server_out << Parser::getResource(message);
	server_out << " ";
	server_out << Parser::getProtocol(message) << std::endl;
	std::string out = server_out.str();
	std::cout << out << std::endl;
}

Impressor::~Impressor() {}
