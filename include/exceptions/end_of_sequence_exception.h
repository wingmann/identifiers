#ifndef WINGMANN_IDENTIFIERS_EXCEPTIONS_END_OF_SEQUENCE_EXCEPTION_H
#define WINGMANN_IDENTIFIERS_EXCEPTIONS_END_OF_SEQUENCE_EXCEPTION_H

#include "identifier_exception.h"

class EndOfSequenceException : public IdentifierException {
public:
    EndOfSequenceException() : IdentifierException{"End of sequence reached."} {}
};

#endif // WINGMANN_IDENTIFIERS_EXCEPTIONS_END_OF_SEQUENCE_EXCEPTION_H
