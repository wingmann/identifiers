#ifndef END_OF_SEQUENCE_EXCEPTION_H
#define END_OF_SEQUENCE_EXCEPTION_H

#include "identifier_exception.h"

class EndOfSequenceException : public IdentifierException {
public:
    EndOfSequenceException() : IdentifierException("End of sequence reached.")
    {
    }
};

#endif // END_OF_SEQUENCE_EXCEPTION_H
