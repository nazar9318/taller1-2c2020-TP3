#include "server_user.hpp"

ServerUser::ServerUser(int argc, char* argv[]) :
server(NULL, argv[1], true) {
    std::string root = "root";
	this->resources.store(root, Protocol::getBodyFile(argv[2]));
}

void ServerUser::ejecutar() {
	this->server.listen();
	ThreadAccepter accepter(this->server, this->resources);
	accepter.start();
	std::string command = "";
	std::cin >> command;
	while (command.compare("q") != 0) {
		std::cout << "Comando inválido\n";
	}
	accepter.stop();
	accepter.join();
}

ServerUser::~ServerUser() {}
