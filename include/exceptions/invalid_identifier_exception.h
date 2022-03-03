#ifndef INVALID_IDENTIFIER_EXCEPTION_H
#define INVALID_IDENTIFIER_EXCEPTION_H

#include "identifier_exception.h"

class InvalidIdentifierException : public IdentifierException {
public:
    InvalidIdentifierException(const char* message) : IdentifierException(message)
    {
    }
};

#endif // INVALID_IDENTIFIER_EXCEPTION_H
