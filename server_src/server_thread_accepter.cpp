#include "server_thread_accepter.hpp"

ThreadAccepter::ThreadAccepter(Socket &server, Resource &resources)
: server(server), resources(resources), keep_accepting(true) {}

void ThreadAccepter::stopClients() {
	for (unsigned int i = 0; i < this->accepted.size(); i++) {
		if (!this->accepted[i]->running()) {
			this->accepted[i]->stop();
			this->accepted[i]->join();
			delete this->accepted[i];
			this->accepted.erase(this->accepted.begin() + i);
		}
	}
}

void ThreadAccepter::run() {
	while (keep_accepting) {
		try {
			Socket peer = this->server.accept();
			this->accepted.push_back(new ThreadClient(std::move(peer), this->resources));
			this->accepted.back()->start();
			this->stopClients();
		} catch (const SocketError &e) {
			for (unsigned int i = 0; i < this->accepted.size(); i++) {
				this->accepted[i]->stop();
				this->accepted[i]->join();
				delete this->accepted[i];
				this->accepted.erase(this->accepted.begin() + i);
			}
		} catch (...) {
			std::cout << "Unkown Error\n" << std::endl;
		}
	}
}

void ThreadAccepter::stop() {
	keep_accepting = false;
}

ThreadAccepter::~ThreadAccepter() {}

