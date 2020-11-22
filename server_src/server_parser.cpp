#include "server_parser.hpp"

Parser::Parser() {}

std::string Parser::advanceIn(std::string const &message, size_t p) {
    std::stringstream buffer;
    buffer << message;
    std::string result;
    for (unsigned int i = 0; i < p; i++) {
        buffer >> result;
    }
    return result;
}

std::string Parser::getMethod(std::string const &message) {
	return advanceIn(message, 1);
}

std::string Parser::getResource(std::string const &message) {
	return advanceIn(message, 2);
}

std::string Parser::getProtocol(std::string const &message) {
	return advanceIn(message, 3);
}

std::string Parser::getBodyFile(std::string const &file_name) {
	std::ifstream file;
	file.open(file_name);
	std::stringstream buff;
	buff << file.rdbuf();
	std::string out = buff.str();
	file.close();
	return out;
}

std::string Parser::getBody(std::string const &message) {
	size_t pos_double_jump = message.find("\n\n");
	std::string out = message.substr(pos_double_jump+2);
	return out;
}

Parser::~Parser() {}
