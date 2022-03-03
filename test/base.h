#ifndef TEST_BASE_H
#define TEST_BASE_H

#include <set>

class BaseTestInstance {
private:
    std::set<char> unavailable_characters_;

public:
    BaseTestInstance()
    {
        unavailable_characters_.insert('D');
        unavailable_characters_.insert('F');
        unavailable_characters_.insert('G');
        unavailable_characters_.insert('J');
        unavailable_characters_.insert('M');
        unavailable_characters_.insert('Q');
        unavailable_characters_.insert('V');
    }

public:
    [[nodiscard]] bool is_unavailable_char(char value) const
    {
        return unavailable_characters_.end() != unavailable_characters_.find(value);
    }
};

#endif // TEST_BASE_H
