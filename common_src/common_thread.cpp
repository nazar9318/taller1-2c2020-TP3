#include "common_thread.hpp"

Thread::Thread() {}

void Thread::start() {
	try {
		this->thread = std::thread(&Thread::run, this);
	} catch (const Error &e) {
        std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "Error desconocido\n" << std::endl;
	}
}

void Thread::join() {
    this->thread.join();
}

Thread::Thread(Thread&& other) {
    this->thread = std::move(other.thread);
}

Thread::~Thread() {}
