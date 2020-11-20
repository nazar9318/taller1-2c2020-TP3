#include "server_parser.hpp"

Parser::Parser() {}

std::string Parser::advanceIn(std::string const &message, size_t p) {
    std::stringstream buffer;
    buffer << message;
    std::string result = "";
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
	std::string body = "";
	std::string aux;
	while (!file.eof()) {
		std::getline(file, aux);
		body += aux+"\n";
	}
	return body;
}

std::string Parser::getBody(std::string const &message) {
	std::stringstream buff;
	std::string body = "";
	buff << message;
	std::getline(buff, body);
	while (body.size() > 0) {
		std::getline(buff, body);
	}
	std::string aux;
	body = "";
	while (!buff.eof()) {
		std::getline(buff, aux);
		body += aux+"\n";
	}
	return body;
}

Parser::~Parser() {}

