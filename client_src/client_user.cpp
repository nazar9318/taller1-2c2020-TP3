#include "client_user.hpp"
#include <vector>
#include <sstream>

ClientUser::ClientUser(int argc, char* argv[]) : 
client(argv[1], argv[2], false) {
	if (argc != 3) {
		throw(" cantidad de argumentos inválida\n");
	}
}

void ClientUser::run() {
	try {
		std::stringbuf buffer_in;
		std::cin.get(buffer_in, EOF);
		std::string message = buffer_in.str();
		this->client.send((unsigned char*)message.c_str(), message.size());
		this->client.stopSending();
		int recvd = 0;
		std::stringstream out;
		do {
			std::vector<uint8_t> buffer(64);
			recvd = this->client.recv(buffer.data(), buffer.size());
			std::string response(buffer.begin(), buffer.end());
			out << response.substr(0, recvd);
		} while (recvd > 0);
		std::cout << out.str();
		this->client.stopReceiving();
	} catch (const SocketError &e) {
		std::cout << e.what() << std::endl;
	}
}

void ClientUser::ejecutar() {
	this->run();
}

ClientUser::~ClientUser() {}
