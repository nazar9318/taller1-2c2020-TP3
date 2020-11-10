#ifndef CLIENT_THREAD_H
#define CLIENT_THREAD_H

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
