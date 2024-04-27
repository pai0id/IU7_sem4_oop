#pragma once

#include "const_iterator.h"
#include "iterator_exceptions.h"
#include <memory>
#include <ctime>

template<CopyNMoveable Type>
ConstListIterator<Type>::ConstListIterator(const ConstListIterator<Type>& other) : wptr(other.wptr.lock()) {}

template<CopyNMoveable Type>
ConstListIterator<Type>::ConstListIterator(const List<Type>::ListNode::node_ptr node) : wptr(node) {}

template<CopyNMoveable Type>
ConstListIterator<Type>::ConstListIterator(const ListIterator<Type>& other) : wptr(other.wptr.lock()) {}

template<CopyNMoveable Type>
ConstListIterator<Type> ConstListIterator<Type>::operator=(const ConstListIterator<Type>& other)
{
    this->wptr = other.wptr.lock();
    return *this;
}

template<CopyNMoveable Type>
ConstListIterator<Type> ConstListIterator<Type>::operator=(const ListIterator<Type> &other)
{
    this->wptr = other.wptr.lock();
    return *this;
}

template<CopyNMoveable Type>
typename ConstListIterator<Type>::reference ConstListIterator<Type>::operator*() const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return *this->wptr.lock()->GetData();
}

template<CopyNMoveable Type>
typename ConstListIterator<Type>::pointer ConstListIterator<Type>::operator->() const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->wptr.lock()->GetData();
}

template<CopyNMoveable Type>
ConstListIterator<Type>::operator bool() const
{
    return IsValid();
}

template<CopyNMoveable Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator++()
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    this->wptr = this->wptr.lock()->GetNext();
    return *this;
}

template<CopyNMoveable Type>
ConstListIterator<Type> ConstListIterator<Type>::operator++(int)
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    ConstListIterator<Type> temp(*this);
    ++(*this);
    return temp;
}

template<CopyNMoveable Type>
bool ConstListIterator<Type>::operator==(const ConstListIterator<Type>& other) const
{
    return wptr.lock() == other.wptr.lock();
}

template<CopyNMoveable Type>
bool ConstListIterator<Type>::operator!=(const ConstListIterator<Type>& other) const
{
    return wptr.lock() != other.wptr.lock();
}


template<CopyNMoveable Type>
bool ConstListIterator<Type>::IsValid() const noexcept
{
    if (wptr.lock() == nullptr)
        return false;
    if (wptr.expired())
        return false;
    return true;
}


template<CopyNMoveable Type>
List<Type>::ListNode::node_ptr ConstListIterator<Type>::getNode() const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return wptr.lock();
}
