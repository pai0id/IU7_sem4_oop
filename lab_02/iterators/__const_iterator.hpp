#pragma once

#include "const_iterator.h"
#include <memory>
#include <ctime>

template<CopyNMoveable Type>
ConstListIterator<Type>::ConstListIterator(const List<Type>::ListNode::node_ptr node) : currentNode(node) {}

template<CopyNMoveable Type>
ConstListIterator<Type>::ConstListIterator(const ConstListIterator<Type>& other) : currentNode(other.currentNode) {}

template<CopyNMoveable Type>
ConstListIterator<Type> ConstListIterator<Type>::operator=(const ConstListIterator<Type>& other)
{
    if (this != &other)
    {
        currentNode = other.currentNode;
    }
    return *this;
}

template<CopyNMoveable Type>
typename ConstListIterator<Type>::reference ConstListIterator<Type>::operator*() const
{
    checkValid(__LINE__);
    return *currentNode->GetData();
}

template<CopyNMoveable Type>
typename ConstListIterator<Type>::pointer ConstListIterator<Type>::operator->() const
{
    checkValid(__LINE__);
    return currentNode->GetData();
}

template<CopyNMoveable Type>
ConstListIterator<Type>::operator bool() const
{
    return IsValid();
}

template<CopyNMoveable Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator++()
{
    checkValid(__LINE__);
    currentNode = currentNode->GetNext();
    return *this;
}

template<CopyNMoveable Type>
ConstListIterator<Type> ConstListIterator<Type>::operator++(int)
{
    checkValid(__LINE__);
    ConstListIterator<Type> temp(*this);
    ++(*this);
    return temp;
}

template<CopyNMoveable Type>
bool ConstListIterator<Type>::operator==(const ConstListIterator<Type>& other) const
{
    return currentNode == other.currentNode;
}

template<CopyNMoveable Type>
bool ConstListIterator<Type>::operator!=(const ConstListIterator<Type>& other) const
{
    return !(*this == other);
}


template<CopyNMoveable Type>
bool ConstListIterator<Type>::IsValid() const
{
    return currentNode != nullptr;
}


template<CopyNMoveable Type>
List<Type>::ListNode::node_ptr ConstListIterator<Type>::getNode() const
{
    return currentNode;
}


template<CopyNMoveable Type>
void ConstListIterator<Type>::checkValid(size_t line) const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}
