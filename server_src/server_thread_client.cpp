#include "server_thread_client.hpp"
#include <mutex>

ThreadClient::ThreadClient(Socket&& peer, Resource &resources) :
peer(std::move(peer)), resources(resources), is_running(true) {}

std::string ThreadClient::receiveFromClient() {
	std::stringstream stream;
	int recvd = 0;
	std::vector<uint8_t> buff;
	recvd = this->peer.recv(buff);
	std::string response(buff.begin(), buff.end());
	this->peer.stopReceiving();
	return response.substr(0, recvd);;
}

void ThreadClient::answerToClient(std::string const& message) {
	Response answer(this->resources);
	std::string resp = answer(message);
	std::vector<uint8_t> to_send(resp.begin(), resp.end());
	this->peer.send(to_send);
	this->peer.stopSending();
	std::mutex m;
	Lock lock(m);
	Impressor out;
	out(message);
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
