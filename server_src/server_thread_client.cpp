#include <utility>
#include "server_thread_client.hpp"

ThreadClient::ThreadClient(Socket&& peer, Resource &resources) :
peer(peer), resources(resources), is_running(true) {}

void ThreadClient::run() {
    int recv = 0;
    size_t total = 0;
    std::vector<uint8_t> buffer(64);
    do {
        recv = this->peer.recv(buffer.data(), buffer.size());
        total += recv;
        if (total >= buffer.size()) {
            buffer.resize(total);
        }
    } while (recv > 0);
    std::string message(buffer.begin(), buffer.end());
    Impressor out;
    out(message);
    Response answer(this->resources);
    std::string resp = answer(message);
    std::vector<uint8_t> resp_sent(resp.begin(), resp.end());
    this->peer.send(resp_sent.data(), resp_sent.size());
    is_running = false;
}

bool ThreadClient::running() const {
    return this->is_running;
}

void ThreadClient::stop() {
    this->peer.close();
}

ThreadClient::~ThreadClient() {}
