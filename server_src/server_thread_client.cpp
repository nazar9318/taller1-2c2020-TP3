#include <utility>
#include <syslog.h>
#include "server_thread_client.hpp"

ThreadClient::ThreadClient(Socket&& peer, Resource &resources) :
peer(std::move(peer)), resources(resources), is_running(true) {}

std::string ThreadClient::receiveMessage() {
	std::stringstream stream;
	int recvd = 0;
        do {
            std::vector<uint8_t> buffer(64);
            recvd = this->peer.recv(buffer.data(), buffer.size());
            std::string response(buffer.begin(), buffer.end());
            stream << response;
        } while (recvd > 0);
	std::string message = stream.str();
    this->peer.stopReceiving();
	return message;
}

void ThreadClient::run() {
    try {
        std::string message = this->receiveMessage();
        Impressor out;
        out(message);
        Response answer(this->resources);
        std::string resp = answer(message);
        std::vector<uint8_t> resp_to_send(resp.begin(), resp.end());
        this->peer.send(resp_to_send.data(), resp_to_send.size());
        this->peer.stopSending();
        this->is_running = false;
    } catch (const SocketError &e) {
        std::cout << e.what() << std::endl;
    }
}

bool ThreadClient::running() const {
    return this->is_running;
}

void ThreadClient::stop() {
    this->peer.close();
}

ThreadClient::~ThreadClient() {}

