#include <utility>
#include "server_thread_client.hpp"

ThreadClient::ThreadClient(Socket&& peer, Resource &resources) :
peer(peer), resources(resources) {}

void ThreadClient::run() {
    std::string recvd = "";
    std::string message = "";
    int recv = 0;
    do {
        recv = this->peer.recv((unsigned char*)recvd.c_str(), 64);
        message += recvd;
        recvd = "";
    } while (recv > 0);
    Response answer(this->resources);
    std::string resp = answer(message);
    this->peer.send((unsigned char*)resp.c_str(), resp.size());
    this->stop();
}

void ThreadClient::stop() {
    this->peer.close();
}

ThreadClient::~ThreadClient() {}
