#ifndef CONST_ITER_IMPL_H
#define CONST_ITER_IMPL_H

#include "const_iterator.h"

template<typename Type>
ConstListIterator<Type>::ConstListIterator(std::shared_ptr<typename List<Type>::ListNode>& node)
    : currentNode(node) {}

template<typename Type>
ConstListIterator<Type>::ConstListIterator(const ConstListIterator<Type>& other)
    : currentNode(other.currentNode) {}

template<typename Type>
ConstListIterator<Type> ConstListIterator<Type>::operator=(const ConstListIterator<Type>& other) {
    if (this != &other) {
        currentNode = other.currentNode;
    }
    return *this;
}

template<typename Type>
typename ConstListIterator<Type>::reference ConstListIterator<Type>::operator*() const {
    checkValid(__LINE__);
    return currentNode->data;
}

template<typename Type>
typename ConstListIterator<Type>::pointer ConstListIterator<Type>::operator->() const {
    checkValid(__LINE__);
    return &(currentNode->data);
}

template<typename Type>
ConstListIterator<Type>::operator bool() const {
    return IsValid();
}

template<typename Type>
ConstListIterator<Type>& ConstListIterator<Type>::operator++() {
    checkValid(__LINE__);
    currentNode = currentNode->next;
    return *this;
}

template<typename Type>
ConstListIterator<Type> ConstListIterator<Type>::operator++(int) {
    checkValid(__LINE__);
    ConstListIterator<Type> temp(*this);
    ++(*this);
    return temp;
}

template<typename Type>
bool ConstListIterator<Type>::operator==(const ConstListIterator<Type>& other) const {
    return currentNode == other.currentNode;
}

template<typename Type>
bool ConstListIterator<Type>::operator!=(const ConstListIterator<Type>& other) const {
    return !(*this == other);
}


template<typename Type>
bool ConstListIterator<Type>::IsValid() const {
    return currentNode != nullptr;
}


template<typename Type>
std::shared_ptr<typename List<Type>::ListNode> ConstListIterator<Type>::getNode() const {
    return currentNode;
}


template<typename Type>
void ConstListIterator<Type>::checkValid(size_t line) const {
    if (!IsValid()) {
        throw std::runtime_error("Iterator is not valid at line: " + std::to_string(line));
    }
}

#endif