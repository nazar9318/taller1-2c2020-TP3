#include "socket_error.hpp"

SocketError::SocketError(const char* fmt, int found, int line) noexcept :
Error(fmt, found, line) {}

SocketError::SocketError(const char* fmt) noexcept :
Error(fmt) {}

const char* SocketError::what() const noexcept {
	return this->msg;
}

SocketError::~SocketError() {}
