#include "identifier.h"
#include "end_of_sequence_exception.h"
#include "invalid_identifier_exception.h"

Identifier::Identifier(const std::string& value)
{
    std::size_t begin{};
    std::size_t end = value.find(group_separator_, begin);

    while (end != std::string::npos) {
        identifier_groups_.emplace_back(value.substr(begin, end - begin));

        begin = end + 1;
        end = value.find(group_separator_, begin);
    }

    identifier_groups_.emplace_back(value.substr(begin));

    if (identifier_groups_.size() > max_group_count_)
        throw InvalidIdentifierException("Too many groups in identifier.");
}

void Identifier::increase()
{
    auto it = identifier_groups_.rbegin();

    for (; identifier_groups_.rend() != it; ++it) {
        IdentifierGroup& id_group = *it;
        id_group.increase();

        if (id_group.get_value() != IdentifierGroup::get_standard_start())
            break;
    }

    if (it == identifier_groups_.rend())
        add_new_group();
}

std::string Identifier::get_value() const
{
    std::string result;
    auto it = identifier_groups_.begin();

    // identifier_groups_ always contains at least one group.
    while (true) {
        result += it->get_value();
        ++it;

        if (it == identifier_groups_.end())
            break;

        result.push_back(group_separator_);
    }

    return result;
}

void Identifier::add_new_group()
{
    // First group was incremented.
    auto incremented =
        identifier_groups_.front().get_value() == IdentifierGroup::get_standard_start();

    if (incremented) {
        auto valid_count = identifier_groups_.size() < max_group_count_;

        // Add a new group to the beginning of the sequence.
        valid_count
            ? identifier_groups_.push_front(IdentifierGroup{IdentifierGroup::get_standard_start()})
            : throw EndOfSequenceException();
    }
}
