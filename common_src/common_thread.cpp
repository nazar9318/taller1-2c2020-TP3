#include <utility>
#include "common_thread.hpp"
#include "socket_error.hpp"

Thread::Thread() {}

void Thread::start() {
	try {
		this->thread = std::thread(&Thread::run, this);
	} catch (...) {}
}

void Thread::join() {
    this->thread.join();
}

Thread::Thread(Thread&& other) {
    this->thread = std::move(other.thread);
}

Thread::~Thread() {}
