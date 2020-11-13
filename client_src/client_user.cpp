#include "client_user.hpp"

ClientUser::ClientUser(int argc, char* argv[]) : 
client(argv[1], argv[2], false) {
    if (argc != 3) {
        throw(" cantidad de argumentos inválida\n");
    }
}

void ClientUser::ejecutar() {
    std::string message;
    std::cin >> message;
    this->client.send((unsigned char*)message.c_str(), message.size());
    std::string recvd = "";
    std::string response = "";
    int recv = 0;
    do {
        recv = this->client.recv((unsigned char*)recvd.c_str(), 64);
        response += recvd;
        recvd = "";
    } while (recv > 0);
    std::cout << response << std::endl;
}

void ClientUser::run() {
    this->ejecutar();
}

ClientUser::~ClientUser() {}
