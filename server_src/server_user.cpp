#include "server_user.hpp"

ServerUser::ServerUser(int argc, char* argv[]) :
server(NULL, argv[1], true) {
	if (argc != 3) {
		throw Error("Cantidad de argumentos inválida %d\n", errno);
	}
	std::string root = "root";
	this->resources.store(root, Parser::getBodyFile(argv[2]));
}

void ServerUser::ejecutar() {
	try {
		this->server.listen();
		ThreadAccepter accepter(this->server, this->resources);
		accepter.start();
		std::string command = "";
		std::cin >> command;
		while (command.compare("q") != 0) {
			std::cout << "Comando inválido\n";
			std::cin >> command;
		}
		accepter.stop();
		this->server.close();
		accepter.join();	
	} catch (const SocketError &e) {
		std::cout << e.what() << std::endl;
	} catch (const Error &e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unkown Error\n" << std::endl;
	}
}

ServerUser::~ServerUser() {}
