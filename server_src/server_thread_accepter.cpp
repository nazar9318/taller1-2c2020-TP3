#include "server_thread_accepter.hpp"

ThreadAccepter::ThreadAccepter(Socket &server, Resource &resources)
: server(server), resources(resources), keep_accepting(true) {}

void ThreadAccepter::stopClients() {
	for (unsigned int i = 0; i < this->accepted.size(); i++) {
		if (!this->accepted[i]->running()) {
			this->accepted[i]->stop();
			this->accepted[i]->join();
			delete this->accepted[i];
		}
	}
}

void ThreadAccepter::run() {
	try {
		while (keep_accepting) {
			Socket peer = this->server.accept();
			this->accepted.push_back(new ThreadClient(std::move(peer), this->resources));
			this->accepted.back()->start();
			this->stopClients();
		}
    } catch (const SocketError &e) {
        std::cout << e.what() << std::endl;
    }
}

void ThreadAccepter::stop() {
	keep_accepting = false;
	for (unsigned int i = 0; i < this->accepted.size(); i++) {
		this->accepted[i]->stop();
		this->accepted[i]->join();
		delete this->accepted[i];
	}
}

ThreadAccepter::~ThreadAccepter() {}
