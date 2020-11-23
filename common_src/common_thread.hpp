#ifndef COMMON_THREAD_H
#define COMMON_THREAD_H

#include <utility>
#include "common_error.hpp"
#include <thread>

class Thread {
    private:
        std::thread thread;
    public:
        Thread();
        void start();
        void join();
        virtual void run() = 0;
        virtual ~Thread();
        Thread(const Thread&) = delete;
        Thread(Thread&& other);
};

#endif
