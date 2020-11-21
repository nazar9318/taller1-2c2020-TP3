#include "client_user.hpp"

int main(int argc, char* argv[]) {
    try {
        ClientUser client(argc, argv);
        client.ejecutar();
        return 0;
    } catch (const SocketError &e) {
        std::cout << e.what() << std::endl;
        return 0;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 0;
    } catch (...) {
        std::cout << "Error desconocido\n" << std::endl;
        return 0;
    }
}
