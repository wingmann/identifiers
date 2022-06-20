#ifndef WINGMANN_IDENTIFIERS_IDENTIFIER_GROUP_H
#define WINGMANN_IDENTIFIERS_IDENTIFIER_GROUP_H

#include <string>

/**
 * Identifier group consists of one letter and one digit.
 */
class IdentifierGroup {
private:
    /**
     * Identifier group.
     */
    std::string value_;

public:
    /**
     * Initialization.
     */
    explicit IdentifierGroup(std::string value, bool check_string = true);

public:
    /**
     * Increments current sequence expression.
     */
    void increase();

    /**
     * Returns a string with the beginning of the sequence.
     * @return Beginning of the sequence.
     */
    constexpr static auto get_standard_start() {
        return "A1";
    }

    /**
     * Returns current value of identifier sequence.
     * @return Current identifier.
     */
    [[nodiscard]] const std::string& get_value() const {
        return value_;
    }

private:
    void check_length();
    void check_letter();
    void check_digit();

    static bool is_letter_valid(char letter);
    static bool is_digit_valid(char digit);

    // Increments letter.
    void increase_letter();

    // Returns true if after incrementing the number went over digit 9 to 1.
    bool increase_number();
};

#endif // WINGMANN_IDENTIFIERS_IDENTIFIER_GROUP_H
