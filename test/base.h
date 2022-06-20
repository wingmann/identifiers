#ifndef TEST_BASE_H
#define TEST_BASE_H

#include <set>

class BaseTestInstance {
private:
    std::set<char> unavailable_characters_;

public:
    BaseTestInstance() : unavailable_characters_{'D', 'F', 'G', 'J', 'M', 'Q', 'V'}
    {
    }

public:
    [[nodiscard]] bool is_unavailable_char(char value) const
    {
        return unavailable_characters_.end() != unavailable_characters_.find(value);
    }
};

#endif // TEST_BASE_H
