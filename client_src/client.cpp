#include "client_user.hpp"
#include <syslog.h>

int main(int argc, char* argv[]) {
    try {
        ClientUser client(argc, argv);
        client.ejecutar();
    } catch (const SocketError &e) {
        syslog(LOG_CRIT, "Error: %s\n", e.what());
        return 0;
    } catch (const std::exception &e) {
        syslog(LOG_CRIT, "Error: %s\n", e.what());
        return 0;
    }
    return 0;
}
