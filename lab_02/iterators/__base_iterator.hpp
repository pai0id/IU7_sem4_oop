#pragma once

#include "base_iterator.h"
#include "iterator_exceptions.h"
#include <ctime>

template<typename Type>
bool BaseIterator<Type>::IsValid() const noexcept
{
    if (wptr.lock() == nullptr)
        return false;
    if (wptr.expired())
        return false;
    return true;
}

template<typename Type>
BaseIterator<Type>::operator bool() const noexcept
{
    return IsValid();
}

template<typename Type>
bool BaseIterator<Type>::operator==(const BaseIterator<Type>& other) const noexcept
{
    return wptr.lock() == other.wptr.lock();
}

template<typename Type>
bool BaseIterator<Type>::operator!=(const BaseIterator<Type>& other) const noexcept
{
    return wptr.lock() != other.wptr.lock();
}

template<typename Type>
List<Type>::ListNode::node_ptr BaseIterator<Type>::getNode() const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return wptr.lock();
}
