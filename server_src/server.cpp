#include "server_user.hpp"
#include "../common_src/common_socket.hpp"

int main(int argc, char* argv[]) {
    try {
        ServerUser server(argc, argv);
        server.ejecutar();
        return 0;
    } catch (const SocketError &e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
