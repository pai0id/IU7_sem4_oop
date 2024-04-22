#pragma once

#include "range.h"

template <InputIterator Iter>
Range<Iter>::Range(Iter fst, Iter lst)
{
    first = fst;
    last = lst;
}

template <InputIterator Iter>
Range<Iter>::iterator Range<Iter>::begin()
{
    return first;
}

template <InputIterator Iter>
Range<Iter>::iterator Range<Iter>::end()
{
    return last;
}

template <InputIterator Iter>
size_t Range<Iter>::size() const noexcept
{
    return distance(first, last);
}