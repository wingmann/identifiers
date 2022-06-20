#ifndef WINGMANN_IDENTIFIERS_EXCEPTIONS_IDENTIFIER_EXCEPTION_H
#define WINGMANN_IDENTIFIERS_EXCEPTIONS_IDENTIFIER_EXCEPTION_H

#include <stdexcept>

class IdentifierException : public std::runtime_error {
public:
    explicit IdentifierException(const char* message) : std::runtime_error{message}
    {
    }
};

#endif // WINGMANN_IDENTIFIERS_EXCEPTIONS_IDENTIFIER_EXCEPTION_H
