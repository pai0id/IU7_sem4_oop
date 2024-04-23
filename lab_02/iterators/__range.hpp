#pragma once

#include "range.h"
#include "range_exceptions.h"

template <ForwardIterator Iter>
Range<Iter>::Range(Iter fst, Iter lst)
{
    if (fst < lst)
    {
        time_t t_time = time(NULL);
        throw InvalidRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
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
    return std::distance(first, last);
}