#include <utility>
#include "common_thread.hpp"

Thread::Thread() {}

void Thread::start() {
   this->thread = std::thread(&Thread::run, this);
}

void Thread::join() {
    this->thread.join();
}

Thread::Thread(Thread&& other) {
    this->thread = std::move(other.thread);
}

Thread::~Thread() {}
