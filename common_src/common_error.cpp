#include "common_error.hpp"

Error::Error(const char* fmt, ...) noexcept {
	int _errno = errno;
	va_list args;
	va_start(args, fmt);
	int s = vsnprintf(this->msg, BUF, fmt, args);
	va_end(args);
	strncpy(msg + s, strerror(_errno), BUF - s);
	msg[BUF - 1] = 0;
}

Error::~Error() noexcept {}
