#include "client_user.hpp"

ClientUser::ClientUser(int argc, char* argv[]) : 
client(argv[1], argv[2], false) {
	if (argc != 3) {
		throw Error("Cantidad de argumentos inválida %d\n", errno);
	}
}

void ClientUser::sendToServer() {
	std::stringbuf buffer_in;
	std::cin.get(buffer_in, EOF);
	std::string message = buffer_in.str();
	std::vector<uint8_t> to_send(message.begin(), message.end());
	this->client.send(to_send);
	this->client.stopSending();	
}

void ClientUser::receiveFromServer() {
	int recvd = 0;
	std::stringstream out;
	std::vector<uint8_t> buff;
	recvd = this->client.recv(buff);
	std::string response(buff.begin(), buff.end());
	std::cout << response.substr(0, recvd);
	this->client.stopReceiving();
}

void ClientUser::run() {
	try {
		this->sendToServer();
		this->receiveFromServer();
	} catch (const SocketError &e) {
		std::cout << e.what() << std::endl;
	} catch (const Error &e) {
		std::cout << e.what() << std::endl;
     } catch (...) {
        std::cout << "Error desconocido\n" << std::endl;
    }
}

void ClientUser::ejecutar() {
	this->run();
}

ClientUser::~ClientUser() {}
