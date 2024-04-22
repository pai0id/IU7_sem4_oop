#pragma once

#include "range.h"

template <ForwardIterator Iter>
Range<Iter>::Range(const Iter &fst, const Iter &lst)
{
    first = fst;
    last = lst;
}

template <ForwardIterator Iter>
Range<Iter>::iterator Range<Iter>::begin()
{
    return first;
}

template <ForwardIterator Iter>
Range<Iter>::iterator Range<Iter>::end()
{
    return last;
}

template <ForwardIterator Iter>
size_t Range<Iter>::size() const noexcept
{
    return distance(first, last);
}