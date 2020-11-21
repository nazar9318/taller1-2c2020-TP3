#include "server_impressor.hpp"

Impressor::Impressor() {}

void Impressor::operator()(std::string const &message) const {
	std::stringstream server_out;
	server_out << Parser::getMethod(message);
	server_out << " ";
	server_out << Parser::getResource(message);
	server_out << " ";
	server_out << Parser::getProtocol(message);
	std::cout << server_out.str() << std::endl;
}

Impressor::~Impressor() {}
