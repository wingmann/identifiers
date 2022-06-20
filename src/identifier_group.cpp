#include "identifier_group.h"
#include "invalid_identifier_exception.h"

#include <sstream>
#include <utility>

IdentifierGroup::IdentifierGroup(std::string value, bool check_string) : value_{std::move(value)}
{
    if (check_string) {
        check_length();
        check_letter();
        check_digit();
    }
}

void IdentifierGroup::increase()
{
    if (increase_number())
        increase_letter();
}

void IdentifierGroup::check_length()
{
    auto is_valid = value_.length() == 2;

    if (!is_valid) {
        std::ostringstream os{};
        os << "Identifier group \"" << value_ << "\" has invalid length.";

        throw InvalidIdentifierException{os.str().c_str()};
    }
}

void IdentifierGroup::check_letter()
{
    auto is_valid = is_letter_valid(value_[0]);

    if (!is_valid) {
        std::ostringstream os{};
        os << "Identifier group \"" << value_ << "\" has invalid letter.\"";

        throw InvalidIdentifierException(os.str().c_str());
    }
}

void IdentifierGroup::check_digit()
{
    auto is_valid = is_digit_valid(value_[1]);

    if (!is_valid) {
        std::ostringstream os;
        os << "Identifier group \"" << value_ << "\" has invalid number.";

        throw InvalidIdentifierException(os.str().c_str());
    }
}

bool IdentifierGroup::is_letter_valid(char letter)
{
    return ('A' <= letter) && ('Z' >= letter) && ('D' != letter) && ('F' != letter) &&
           ('G' != letter) && ('J' != letter) && ('M' != letter) && ('Q' != letter) &&
           ('V' != letter);
}

bool IdentifierGroup::is_digit_valid(char digit)
{
    return ('1' <= digit) && ('9' >= digit);
}

void IdentifierGroup::increase_letter()
{
    char& letter = value_[0];
    ++letter;

    while (!is_letter_valid(letter)) {
        ++letter;

        if ('Z' < letter)
            letter = 'A';
    }
}

bool IdentifierGroup::increase_number()
{
    char& number = value_[1];
    ++number;

    bool result = '9' < number;
    if (result) number = '1';

    return result;
}
