#include "server_thread_client.hpp"

ThreadClient::ThreadClient(Socket&& peer, Resource &resources) :
peer(std::move(peer)), resources(resources), is_running(true) {}

std::string ThreadClient::receiveFromClient() {
	std::stringstream stream;
	int recvd = 0;
    do {
        std::vector<uint8_t> buffer(64);
        recvd = this->peer.recv(buffer.data(), buffer.size());
        std::string response(buffer.begin(), buffer.end());
        stream << response.substr(0, recvd);
    } while (recvd > 0);
	this->peer.stopReceiving();
	return stream.str();
}

void ThreadClient::answerToClient(std::string const& message) {
	Impressor out;
	out(message);
	Response answer(this->resources);
	std::string resp = answer(message);
	std::vector<uint8_t> resp_to_send(resp.begin(), resp.end());
	this->peer.send(resp_to_send.data(), resp_to_send.size());
	this->peer.stopSending();
}

void ThreadClient::run() {
	try {
		std::string message = this->receiveFromClient();
		this->answerToClient(message);
		this->is_running = false;
	} catch (const SocketError &e) {
		if (!this->is_running) {
			std::cout << e.what() << std::endl;
		}
	} catch (const Error &e) {
		if (!this->is_running) {
			std::cout << e.what() << std::endl;
		}
	} catch (...) {
		std::cout << "Unkown Error\n" << std::endl;
	}
}

bool ThreadClient::running() const {
	return this->is_running;
}

void ThreadClient::stop() {
	this->is_running = false;
	this->peer.close();
}

ThreadClient::~ThreadClient() {}
