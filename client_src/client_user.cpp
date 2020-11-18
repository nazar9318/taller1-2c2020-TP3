#include "client_user.hpp"
#include <vector>

ClientUser::ClientUser(int argc, char* argv[]) : 
client(argv[1], argv[2], false) {
    if (argc != 3) {
        throw(" cantidad de argumentos inválida\n");
    }
}

void ClientUser::run() {
    try {
        std::string message;
        std::cin >> message;
        this->client.send((unsigned char*)message.c_str(), message.size());
        int recv = 0;
        size_t total = 0;
        std::vector<uint8_t> buffer(64);
        do {
            recv = this->client.recv(buffer.data(), buffer.size());
            total += recv;
            if (total >= buffer.size()) {
                buffer.resize(total);
            }
        } while (recv > 0);
        std::string response(buffer.begin(), buffer.end());
        std::cout << response << std::endl;
    } catch (const SocketError &e) {
        std::cout << e.what() << std::endl;
    }
}

void ClientUser::ejecutar() {
    this->run();
}

ClientUser::~ClientUser() {}
