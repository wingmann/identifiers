#ifndef IDENTIFIER_EXCEPTION_H
#define IDENTIFIER_EXCEPTION_H

#include <stdexcept>

class IdentifierException : public std::runtime_error {
public:
    IdentifierException(const char* message) :std::runtime_error(message)
    {
    }
};

#endif // IDENTIFIER_EXCEPTION_H
