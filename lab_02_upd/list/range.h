#pragma once

#include "__concepts.hpp"

template <ForwardIterator Iter>
class Range
{
public:
    using value_type = Iter::value_type;
    using size_type = size_t;
    using iterator = Iter;
    using const_iterator = const Iter;

    Range(Iter fst, Iter lst);
    ~Range() = default;

    size_t size() const noexcept;

    iterator begin();
    iterator end();

private:
    Iter first, last;
};

#include "__range.hpp"
