#ifndef WINGMANN_IDENTIFIERS_EXCEPTIONS_INVALID_IDENTIFIER_EXCEPTION_H
#define WINGMANN_IDENTIFIERS_EXCEPTIONS_INVALID_IDENTIFIER_EXCEPTION_H

#include "identifier_exception.h"

class InvalidIdentifierException : public IdentifierException {
public:
    explicit InvalidIdentifierException(const char* message) : IdentifierException{message} {}
};

#endif // WINGMANN_IDENTIFIERS_EXCEPTIONS_INVALID_IDENTIFIER_EXCEPTION_H
