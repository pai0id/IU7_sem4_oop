#ifndef ITER_IMPL_H
#define ITER_IMPL_H

#include <memory>

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
    return currentNode->data;
}

template <typename Type>
const ListIterator<Type>::reference ListIterator<Type>::operator*() const
{
    checkValid(__LINE__);
    return currentNode->data;
}

template <typename Type>
ListIterator<Type>::pointer ListIterator<Type>::operator->()
{
    checkValid(__LINE__);
    return &(currentNode->data);
}

template <typename Type>
const ListIterator<Type>::pointer ListIterator<Type>::operator->() const
{
    checkValid(__LINE__);
    return &(currentNode->data);
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
    currentNode = currentNode->next;
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
        throw std::runtime_error("Iterator is not valid at line " + std::to_string(line));
    }
}

template <typename Type>
std::shared_ptr<typename List<Type>::ListNode> ListIterator<Type>::getNode() const
{
    return currentNode;
}

template <typename Type>
ListIterator<Type>::ListIterator(std::shared_ptr<typename List<Type>::ListNode>& node) : currentNode(node) {}

#endif
