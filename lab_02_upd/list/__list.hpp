#pragma once

#include <ctime>
#include <iostream>
#include "list.h"
#include "exceptions.h"

template <typename Type>
List<Type>::List(const List<Type>& someList)
{
    for (const auto& elem : someList)
    {
        pushBack(elem);
    }
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
List<Type>::List(size_type n, const T& value)
{
    for (size_type i = 0; i < n; ++i)
    {
        pushBack(value);
    }
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
List<Type>::List(std::initializer_list<T> initList)
{
    for (const auto& elem : initList)
    {
        pushBack(elem);
    }
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type>::List(const C& container)
{
    for (const auto& elem : container)
    {
        pushBack(elem);
    }
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type>::List(C&& container)
{
    for (auto&& val : container)
    {
        pushBack(std::move(val));
    }
}

template <typename Type>
template <ForwardIterator Iter>
requires Convertible<typename Iter::value_type, Type>
List<Type>::List(const Iter& begin, const Iter& end)
{
    for (auto it = begin; it != end; ++it)
    {
        pushBack(*it);
    }
}

template <typename Type>
template <ForwardIterator Iter>
requires Convertible<typename Iter::value_type, Type>
List<Type>::List(Range<Iter> range)
{
    for (auto it = range.begin(); it != range.end(); ++it)
    {
        pushBack(*it);
    }
}

template <typename Type>
template <ForwardIterator Iter>
requires Convertible<typename Iter::value_type, Type>
List<Type>::List(const Iter& begin, const size_t size)
{
    auto it = begin;
    for (size_t i = 0; i < size; ++i)
    {
        pushBack(*it);
        ++it;
    }
}

template <typename Type>
List<Type>& List<Type>::operator=(const List<Type>& someList)
{
    if (this == &someList)
    {
        return *this;
    }
    for (const auto& elem : someList)
    {
        pushBack(elem);
    }
    return *this;
}

template <typename Type>
List<Type>& List<Type>::operator=(List<Type>&& someList)
{
    if (this == &someList)
    {
        return *this;
    }
    head = std::move(someList.head);
    tail = std::move(someList.tail);
    csize = std::move(someList.csize);
    return *this;
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type>& List<Type>::operator=(const C& container)
{
    clear();
    for (const auto& val : container)
    {
        pushBack(val);
    }
    return *this;
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type>& List<Type>::operator=(C&& container)
{
    clear();
    for (auto&& val : container)
    {
        pushBack(std::move(val));
    }
    return *this;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
List<Type>& List<Type>::operator=(std::initializer_list<T> someList)
{
    clear();
    for (const auto& val : someList)
    {
        pushBack(val);
    }
    return *this;
}

template <typename Type>
template <ForwardIterator Iter>
requires Convertible<typename Iter::value_type, Type>
List<Type>& List<Type>::operator=(Range<Iter> range)
{
    clear();
    for (auto it = range.begin(); it != range.end(); ++it)
    {
        pushBack(*it);
    }
    return *this;
}

template <typename Type>
typename List<Type>::size_type List<Type>::size() const noexcept
{
    return csize;
}

template <typename Type>
typename List<Type>::iterator List<Type>::begin() noexcept
{
    return iterator(head);
}

template <typename Type>
typename List<Type>::const_iterator List<Type>::begin() const noexcept
{
    return const_iterator(head);
}

template <typename Type>
typename List<Type>::const_iterator List<Type>::cbegin() const noexcept
{
    return const_iterator(head);
}

template <typename Type>
typename List<Type>::iterator List<Type>::end() noexcept
{
    if (tail)
        return ++iterator(tail);
    return iterator(tail);
}

template <typename Type>
typename List<Type>::const_iterator List<Type>::end() const noexcept
{
    if (tail)
        return ++const_iterator(tail);
    return const_iterator(tail);
}

template <typename Type>
typename List<Type>::const_iterator List<Type>::cend() const noexcept
{
    if (tail)
        return ++const_iterator(tail);
    return const_iterator(tail);
}

template <typename Type>
typename List<Type>::iterator List<Type>::getFront()
{
    if (!head)
    {
        time_t t_time = time(NULL);
        throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return iterator(head);
}

template <typename Type>
typename List<Type>::const_iterator List<Type>::getFront() const
{
    if (!head)
    {
        time_t t_time = time(NULL);
        throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return const_iterator(head);
}

template <typename Type>
typename List<Type>::iterator List<Type>::getBack()
{
    if (!tail)
    {
        time_t t_time = time(NULL);
        throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return iterator(tail);
}

template <typename Type>
typename List<Type>::const_iterator List<Type>::getBack() const
{
    if (!tail)
    {
        time_t t_time = time(NULL);
        throw EmptyList(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return const_iterator(tail);
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
void List<Type>::pushFront(const T& data) 
{
    if (!head)
    {
        typename ListNode::node_ptr newNode = ListNode::initNode(data, nullptr);
        head = tail = newNode;
    }
    else
    {
        typename ListNode::node_ptr newNode = ListNode::initNode(data, head);
        head = newNode;
    }
    ++csize;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
void List<Type>::pushFront(T&& data)
{
    if (!head)
    {
        typename ListNode::node_ptr newNode = ListNode::initNode(data, nullptr);
        head = tail = newNode;
    }
    else
    {
        typename ListNode::node_ptr newNode = ListNode::initNode(data, head);
        head = newNode;
    }
    ++csize;
}

template <typename Type>
void List<Type>::popFront() noexcept
{
    if (!head)
    {
        return;
    }
    if (head == tail)
    {
        head.reset();
        tail.reset();
    }
    else
    {
        head = head->GetNext();
    }
    --csize;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
void List<Type>::pushBack(const T& data)
{
    typename ListNode::node_ptr newNode = ListNode::initNode(data, nullptr);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->SetNext(newNode);
        tail = newNode;
    }
    ++csize;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
void List<Type>::pushBack(T&& data)
{
    typename ListNode::node_ptr newNode = ListNode::initNode(data, nullptr);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->SetNext(newNode);
        tail = newNode;
    }
    ++csize;
}

template <typename Type>
void List<Type>::popBack() noexcept
{
    if (!head)
    {
        return;
    }
    if (head == tail)
    {
        head.reset();
        tail.reset();
        csize = 0;
        return;
    }
    auto currentNode = head;
    while (currentNode->GetNext() != tail)
    {
        currentNode = currentNode->GetNext();
    }
    tail = currentNode;
    tail->SetNextNull();
    --csize;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
typename List<Type>::iterator List<Type>::insert(const_iterator pos, const T& data)
{
    if (pos == cbegin())
    {
        pushFront(data);
        return begin();
    }
    else if (pos == cend())
    {
        pushBack(data);
        return iterator(tail);
    }
    else
    {
        auto currentNode = head;
        while (currentNode->GetNext() != pos.getNode())
        {
            currentNode = currentNode->GetNext();
        }
        typename ListNode::node_ptr newNode = ListNode::initNode(data, currentNode->GetNext());
        currentNode->SetNext(newNode);
        ++csize;
        return iterator(newNode);
    }
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
typename List<Type>::iterator List<Type>::insert(const_iterator pos, T&& data)
{
    if (pos == cbegin())
    {
        pushFront(std::move(data));
        return begin();
    }
    else if (pos == cend())
    {
        pushBack(std::move(data));
        return iterator(tail);
    }
    else
    {
        auto currentNode = head;
        while (currentNode->GetNext() != pos.getNode())
        {
            currentNode = currentNode->GetNext();
        }
        typename ListNode::node_ptr newNode = ListNode::initNode(data, currentNode->GetNext());
        currentNode->SetNext(newNode);
        ++csize;
        return iterator(newNode);
    }
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type>& List<Type>::operator+=(const C &container)
{
    for (const auto& val : container)
    {
        pushBack(val);
    }
    return *this;
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type>& List<Type>::operator+=(C &&container)
{
    for (auto&& val : container)
    {
        pushBack(std::move(val));
    }
    return *this;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
List<Type>& List<Type>::operator+=(const T &data)
{
    pushBack(data);
    return *this;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
List<Type>& List<Type>::operator+=(T &&data)
{
    pushBack(std::move(data));
    return *this;
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type> List<Type>::operator+(const C &container) const
{
    List<Type> result(*this);
    for (const auto& val : container)
    {
        result.pushBack(val);
    }
    return result;
}

template <typename Type>
template <Container C>
requires Convertible<typename C::value_type, Type> &&
         ForwardIterator<typename C::iterator>
List<Type> List<Type>::operator+(C &&container) const
{
    List<Type> result(*this);
    for (auto&& val : container)
    {
        result.pushBack(std::move(val));
    }
    return result;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
List<Type> List<Type>::operator+(const T &data) const
{
    List<Type> result(*this);
    result.pushBack(data);
    return result;
}

template <typename Type>
template <typename T>
requires Convertible<T, Type>
List<Type> List<Type>::operator+(T &&data) const
{
    List<Type> result(*this);
    result.pushBack(std::move(data));
    return result;
}

template <typename Type, typename T>
requires Convertible<T, Type>
List<Type> operator+(const T& value, const List<Type>& container)
{
    List<Type> result;
    result.pushBack(value);
    for (const auto& val : container)
    {
        result.pushBack(val);
    }
    return result;
}

template <typename Type, typename T>
requires Convertible<T, Type>
List<Type> operator+(T&& value, const List<Type>& container)
{
    List<Type> result;
    result.pushBack(std::move(value));
    for (const auto& val : container)
    {
        result.pushBack(val);
    }
    return result;
}

template <typename Type>
void List<Type>::reverse() noexcept
{
    if (csize <= 1)
    {
        return;
    }
    
    std::shared_ptr<ListNode> prevNode = nullptr;
    auto currentNode = head;
    auto nextNode = head->GetNext();
    
    tail = head;
    
    while (nextNode)
    {
        currentNode->SetNext(prevNode);
        
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->GetNext();
    }
    
    currentNode->SetNext(prevNode);
    
    head = currentNode;
}

template <typename Type>
void List<Type>::remove(const_iterator pos)
{
    if (pos == cend())
    {
        popBack();
        return;
    }

    if (pos == cbegin())
    {
        popFront();
        return;
    }

    auto prevNode = head;
    auto currentNode = head->GetNext();

    while (currentNode != pos.getNode())
    {
        prevNode = currentNode;
        currentNode = currentNode->GetNext();
    }

    prevNode->SetNext(currentNode->GetNext());
    --csize;

    if (pos.getNode() == tail)
    {
        tail = prevNode;
    }
}

template <typename Type>
void List<Type>::remove(const_iterator st, const_iterator end)
{
    if (st == cbegin() && end == cend())
    {
        clear();
        return;
    }

    auto prevNode = head;
    auto currentNode = head->GetNext();

    while (currentNode != end.getNode())
    {
        if (currentNode == st.getNode())
        {
            prevNode->SetNext(end.getNode());
            csize -= std::distance(st, end);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->GetNext();
    }
}

template <typename Type>
void List<Type>::remove(const_iterator st, size_type n)
{
    auto end = std::next(st, n);
    remove(st, end);
}

template <typename Type>
template <ForwardIterator Iter>
requires Convertible<typename Iter::value_type, Type>
void List<Type>::remove(Range<Iter> range)
{
    remove(range.begin(), range.end());
}

template <typename Type>
void List<Type>::clear() noexcept
{
    head.reset();
    tail.reset();
    csize = 0;
}

template <typename Type>
bool List<Type>::isEmpty() const noexcept
{
    return csize == 0;
}

template <typename T>
std::ostream& operator <<(std::ostream & os, const List<T> & list)
{
	for (auto& elem : list)
		std::cout << elem << " ";

	return os;
}
