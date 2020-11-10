#include "server_user.hpp"
#include "../common_src/common_socket.hpp"
#include <syslog.h>

int main(int argc, char* argv[]) {
    try {
        ServerUser server(argc, argv);
        server.ejecutar();
    } catch (const SocketError &e) {
        syslog(LOG_CRIT, "Error: %s\n", e.what());
    }
    return 0;
}
