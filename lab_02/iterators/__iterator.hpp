#pragma once

#include "iterator.h"
#include "iterator_exceptions.h"
#include <memory>
#include <ctime>

template <CopyNMoveable Type>
ListIterator<Type>::ListIterator(const ListIterator& other) : wptr(other.wptr.lock()) {}

template <CopyNMoveable Type>
ListIterator<Type>::ListIterator(List<Type>::ListNode::node_ptr node) : wptr(node) {}

template <CopyNMoveable Type>
ListIterator<Type>& ListIterator<Type>::operator=(const ListIterator<Type>& other)
{
    this->wptr = other.wptr.lock();
    return *this;
}

template <CopyNMoveable Type>
bool ListIterator<Type>::IsValid() const noexcept
{
    if (wptr.lock() == nullptr)
        return false;
    if (wptr.expired())
        return false;
    return true;
}

template <CopyNMoveable Type>
typename ListIterator<Type>::reference ListIterator<Type>::operator*()
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return *this->wptr.lock()->GetData();
}

template <CopyNMoveable Type>
const ListIterator<Type>::reference ListIterator<Type>::operator*() const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return *this->wptr.lock()->GetData();
}

template <CopyNMoveable Type>
ListIterator<Type>::pointer ListIterator<Type>::operator->()
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->wptr.lock()->GetData();
}

template <CopyNMoveable Type>
const ListIterator<Type>::pointer ListIterator<Type>::operator->() const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->wptr.lock()->GetData();
}

template <CopyNMoveable Type>
ListIterator<Type>::operator bool() const
{
    return IsValid();
}

template <CopyNMoveable Type>
ListIterator<Type>& ListIterator<Type>::operator++()
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    this->wptr = this->wptr.lock()->GetNext();
    return *this;
}

template <CopyNMoveable Type>
ListIterator<Type> ListIterator<Type>::operator++(int)
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    ListIterator<Type> temp(*this);
    ++(*this);
    return temp;
}

template <CopyNMoveable Type>
bool ListIterator<Type>::operator==(const ListIterator<Type>& other) const
{
    return wptr.lock() == other.wptr.lock();
}

template <CopyNMoveable Type>
bool ListIterator<Type>::operator!=(const ListIterator<Type>& other) const
{
    return wptr.lock() != other.wptr.lock();
}

template <CopyNMoveable Type>
List<Type>::ListNode::node_ptr ListIterator<Type>::getNode() const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return wptr.lock();
}
