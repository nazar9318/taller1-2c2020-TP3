#ifndef SOCKET_ERROR_H
#define SOCKET_ERROR_H

#include "common_error.hpp"

class SocketError : public Error {
    public:
        explicit SocketError(const char* fmt, int found, int line) noexcept;

        explicit SocketError(const char* fmt) noexcept;

        const char* what() const noexcept override;
        
        ~SocketError() noexcept; 
};

#endif
