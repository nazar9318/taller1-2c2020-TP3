#include <utility>
#include "server_thread_client.hpp"

ThreadClient::ThreadClient(Socket&& peer, Resource &resources) :
peer(peer), resources(resources) {}//, keep_talking(true) {}

void ThreadClient::run() {
    //while (this->talking()) {
        std::string recvd = "";
        std::string message = "";
        int recv = 0;
        do {
            recv = this->peer.recv((unsigned char*)recvd.c_str(), 64);
            message += recvd;
            recvd = "";
        } while (recv > 0);
        Response answer(this->resources);
        std::cout << Protocol::getMethod(message);
        std::cout << " " + Protocol::getResource(message);
        std::cout << " " + Protocol::getProtocol(message) << std::endl;
        std::string resp = answer.setResponse(message);
        this->peer.send((unsigned char*)resp.c_str(), resp.size());
        this->stop();
    //}
}

void ThreadClient::stop() {
    //this->keep_talking = false;
    this->peer.close();
}

ThreadClient::~ThreadClient() {}
