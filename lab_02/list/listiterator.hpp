#ifndef _LISTITERATOR_HPP_
#define _LISTITERATOR_HPP_

#include <ctime>
#include "listiterator.h"


template <typename T>
IteratorBase<T>::IteratorBase()
{
    this->ptrCur.lock() = nullptr;
}


template <typename T>
IteratorBase<T>::IteratorBase(const std::shared_ptr<ListNode<T>> node) : ptrCur(node)
{
}


template <typename T>
IteratorBase<T>::IteratorBase(const IteratorBase<T>& listIter) : ptrCur(listIter.ptrCur)
{
}


template <typename T>
IteratorBase<T>& IteratorBase<T>::operator=(const IteratorBase<T>& listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;

    return *this;
}

template <typename T>
IteratorBase<T>& IteratorBase<T>::next()
{
    if (this->ptrCur.expired()) 
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    this->ptrCur = this->ptrCur.lock()->getNext();
    return *this;
}

template <typename T>
IteratorBase<T>& IteratorBase<T>::operator++()
{
    return this->next();
}

template <typename T>
IteratorBase<T> IteratorBase<T>::operator++(int)
{
    IteratorBase<T> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename T>
bool IteratorBase<T>::checkRange() const
{
    return (this->ptrCur.lock() == nullptr) ? false : true;
}

template <typename T>
bool IteratorBase<T>::operator==(const IteratorBase<T>& listIter) const
{
    return this->ptrCur.lock() == listIter.ptrCur.lock();
}

template <typename T>
bool IteratorBase<T>::operator!=(const IteratorBase<T>& listIter) const
{
    return this->ptrCur.lock() != listIter.ptrCur.lock();
}

template <typename T>
Iterator<T>::Iterator()
{
    this->ptrCur.lock() = nullptr;
}

template <typename T>
Iterator<T>::Iterator(const Iterator<T>& listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename T>
Iterator<T>::Iterator(const std::shared_ptr<ListNode<T>> node)
{
    this->ptrCur = node;
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;

    return *this;
}

template <typename T>
T& Iterator<T>::getCur()
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T& Iterator<T>::getCur() const
{
    if (this->ptrCur.expired()) 
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
T& Iterator<T>::getNext()
{
    if (this->ptrCur.expired() || this->ptrCur.lock() == this->end() || this->ptrCur.next().lock() == this->end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return this->ptrCur.next().lock()->getPtrData();
}

template <typename T>
const T& Iterator<T>::getNext() const
{
    if (this->ptrCur.expired() || this->ptrCur.lock() == this->end() || this->ptrCur.next().lock() == this->end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return this->ptrCur.next().lock()->getPtrData();
}

template <typename T>
T& Iterator<T>::operator*()
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T& Iterator<T>::operator*() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
T* Iterator<T>::operator->()
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return &this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T* Iterator<T>::operator->() const
{
    if (this->ptrCur.expired())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time)); 
    }
    return &this->ptrCur.lock()->getPtrData();
}

template <typename T>
Iterator<T>::operator bool() const noexcept
{
    return &this->ptrCur.expired();
}

#endif
