#pragma once

#include "iterator.h"
#include "exceptions.h"
#include <memory>
#include <ctime>

template <typename Type>
ListIterator<Type>::ListIterator(const ListIterator& other) : currentNode(other.currentNode) {}

template <typename Type>
ListIterator<Type>& ListIterator<Type>::operator=(const ListIterator<Type>& other)
{
    if (this != &other) {
        currentNode = other.currentNode;
    }
    return *this;
}

template <typename Type>
bool ListIterator<Type>::IsValid() const
{
    return currentNode != nullptr;
}

template <typename Type>
typename ListIterator<Type>::reference ListIterator<Type>::operator*()
{
    checkValid(__LINE__);
    return *currentNode->GetData();
}

template <typename Type>
const ListIterator<Type>::reference ListIterator<Type>::operator*() const
{
    checkValid(__LINE__);
    return *currentNode->GetData();
}

template <typename Type>
ListIterator<Type>::pointer ListIterator<Type>::operator->()
{
    checkValid(__LINE__);
    return currentNode->GetData();
}

template <typename Type>
const ListIterator<Type>::pointer ListIterator<Type>::operator->() const
{
    checkValid(__LINE__);
    return currentNode->GetData();
}

template <typename Type>
ListIterator<Type>::operator bool() const
{
    return IsValid();
}

template <typename Type>
ListIterator<Type>& ListIterator<Type>::operator++()
{
    checkValid(__LINE__);
    currentNode = currentNode->GetNext();
    return *this;
}

template <typename Type>
ListIterator<Type> ListIterator<Type>::operator++(int)
{
    checkValid(__LINE__);
    ListIterator<Type> temp(*this);
    ++(*this);
    return temp;
}

template <typename Type>
bool ListIterator<Type>::operator==(const ListIterator<Type>& other) const
{
    return currentNode == other.currentNode;
}

template <typename Type>
bool ListIterator<Type>::operator!=(const ListIterator<Type>& other) const
{
    return !(*this == other);
}

template <typename Type>
void ListIterator<Type>::checkValid(size_t line) const
{
    if (!IsValid())
    {
        time_t t_time = time(NULL);
        throw ListOutOfBounds(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <typename Type>
List<Type>::ListNode::node_ptr ListIterator<Type>::getNode() const
{
    return currentNode;
}

template <typename Type>
ListIterator<Type>::ListIterator(List<Type>::ListNode::node_ptr node) : currentNode(node) {}
