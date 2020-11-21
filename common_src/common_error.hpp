#ifndef COMMON_ERROR_H
#define COMMON_ERROR_H

#include <iostream>
#include <errno.h>
#include <cstdio>
#include <typeinfo>
#include <cstdarg>
#include <string.h>
#define BUF 256

class Error : public std::exception {
    protected:
        char msg[BUF];
    public:
        explicit Error(const char* fmt, ...) noexcept;

        virtual const char *what() const noexcept;
        
        virtual ~Error() noexcept;
};

#endif
