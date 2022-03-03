#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "identifier_group.h"

#include <list>
#include <string>
#include <cstddef>

/**
 * Contains the list of group.
 */
class Identifier {
private:
    // Group list.
    std::list<IdentifierGroup> identifier_groups_;

    // Maximum number of groups in identifier.
    static const std::size_t max_group_count_{10};

    // Group separator.
    static const char group_separator_{'-'};

public:
    /**
     * Initialization.
     * @param value
     */
    explicit Identifier(const std::string& value);

public:
    void increase();

    [[nodiscard]] std::string get_value() const;

private:
    // Add a new group to the top of the list.
    void add_new_group();
};

#endif // IDENTIFIER_H
