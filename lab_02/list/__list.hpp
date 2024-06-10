#pragma once

#include <ctime>
#include <iostream>
#include "list.h"
#include "list_exceptions.h"
#include "iterator_exceptions.h"
#include "range_exceptions.h"

template <CopyNMoveable Type>
List<Type>::List(const List<Type>& someList)
{
    std::for_each(someList.cbegin(), someList.cend(), [this](const Type& elem){ pushBack(elem);});
}

template <CopyNMoveable Type>
List<Type>::List(List<Type>&& someList) noexcept :
    head(std::exchange(someList.head, nullptr)),
    tail(std::exchange(someList.tail, nullptr)),
    csize(std::exchange(someList.csize, 0)) {}

template <CopyNMoveable Type>
template <Convertable<Type> T>
List<Type>::List(size_type n, const T& value)
{
    for (size_type i = 0; i < n; ++i) { pushBack(value); }
}

template <CopyNMoveable Type>
template <Convertable<Type> T>
List<Type>::List(std::initializer_list<T> initList)
{
    for (auto elem : initList) pushBack(elem);
}

// template <CopyNMoveable Type>
// template <ConvertableForwardContainer<Type> C>
// List<Type>::List(const C& container)
// {
//     std::for_each(container.cbegin, container.cend, [this](const Type& elem){ pushBack(elem);});
// }

template <CopyNMoveable Type>
template <ConvertableForwardIterator<Type> I>
List<Type>::List(const I& begin, const I& end)
{
    std::for_each(begin, end, [this](const Type& elem){ pushBack(elem);});
}

template <CopyNMoveable Type>
template <ConvertableForwardIterator<Type> I>
List<Type>::List(const I& begin, const size_t size)
{
    auto end = begin + size;
    std::for_each(begin, end, [this](const Type& elem){ pushBack(elem);});
}

template <CopyNMoveable Type>
template<std::ranges::input_range Range>
requires requires(typename Range::value_type t)  {{ t }  -> std::convertible_to<Type>; }
List<Type>::List(const Range& range) : List(range.cbegin(), range.cend())
{}

template <CopyNMoveable Type>
List<Type> List<Type>::SubList(iterator &begin, iterator &end)
{
    validateListIterartorRange(begin, end, __LINE__);

    return List<Type>(begin, end);
}

template <CopyNMoveable Type>
List<Type> List<Type>::SubList(iterator &begin, const size_type size)
{
    auto end = std::next(begin, size);
    validateListIterartorRange(begin, end, __LINE__);

    return List<Type>(begin, end);
}

template <CopyNMoveable Type>
List<Type> List<Type>::SubList(const_iterator &begin, const_iterator &end) const
{
    validateListIterartorRange(begin, end, __LINE__);

    return List<Type>(begin, end);
}

template <CopyNMoveable Type>
List<Type> List<Type>::SubList(const_iterator &begin, const size_type size) const
{
    auto end = std::next(begin, size);
    validateListIterartorRange(begin, end, __LINE__);

    return List<Type>(begin, end);
}

template <CopyNMoveable Type>
List<Type>& List<Type>::operator=(const List<Type>& someList)
{
    clear();
    std::for_each(someList.cbegin(), someList.cend(), [this](const Type& elem){ pushBack(elem);});
    return *this;
}

template <CopyNMoveable Type>
List<Type>& List<Type>::operator=(List<Type>&& someList) noexcept
{
    head = std::exchange(someList.head, nullptr);
    tail = std::exchange(someList.tail, nullptr);
    csize = std::exchange(someList.csize, 0);
    return *this;
}

template <CopyNMoveable Type>
template <Convertable<Type> T>
List<Type>& List<Type>::operator=(std::initializer_list<T> initList)
{
    clear();
    for (auto elem : initList) pushBack(elem);
    return *this;
}

// template <CopyNMoveable Type>
// template <ConvertableForwardContainer<Type> C>
// List<Type>& List<Type>::operator=(const C& container)
// {
//     clear();
//     std::for_each(container.cbegin, container.cend, [this](const Type& elem){ pushBack(elem);});
//     return *this;
// }

template <CopyNMoveable Type>
template<std::ranges::input_range Range>
requires requires(typename Range::value_type t)  {{ t }  -> std::convertible_to<Type>; }
List<Type>& List<Type>::operator=(const Range& range)
{
    clear();
    std::for_each(std::ranges::begin(range), std::ranges::end(range), [this](const Type& elem){ pushBack(elem);});
    return *this;
}

template <CopyNMoveable Type>
typename List<Type>::size_type List<Type>::size() const noexcept
{
    return csize;
}

template <CopyNMoveable Type>
typename List<Type>::iterator List<Type>::begin() noexcept
{
    return iterator(head);
}

template <CopyNMoveable Type>
typename List<Type>::const_iterator List<Type>::begin() const noexcept
{
    return const_iterator(head);
}

template <CopyNMoveable Type>
typename List<Type>::const_iterator List<Type>::cbegin() const noexcept
{
    return const_iterator(head);
}

template <CopyNMoveable Type>
typename List<Type>::iterator List<Type>::end() noexcept
{
    if (tail)
        return ++iterator(tail);
    return iterator(tail);
}

template <CopyNMoveable Type>
typename List<Type>::const_iterator List<Type>::end() const noexcept
{
    if (tail)
        return ++const_iterator(tail);
    return const_iterator(tail);
}

template <CopyNMoveable Type>
typename List<Type>::const_iterator List<Type>::cend() const noexcept
{
    if (tail)
        return ++const_iterator(tail);
    return const_iterator(tail);
}

template <CopyNMoveable Type>
typename List<Type>::iterator List<Type>::getFront() noexcept
{
    return iterator(head);
}

template <CopyNMoveable Type>
typename List<Type>::const_iterator List<Type>::getFront() const noexcept
{
    return const_iterator(head);
}

template <CopyNMoveable Type>
typename List<Type>::iterator List<Type>::getBack() noexcept
{
    return iterator(tail);
}

template <CopyNMoveable Type>
typename List<Type>::const_iterator List<Type>::getBack() const noexcept
{
    return const_iterator(tail);
}

template <CopyNMoveable Type>
template <Convertable<Type> T>
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

template <CopyNMoveable Type>
template <Convertable<Type> T>
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

template <CopyNMoveable Type>
void List<Type>::pushFront(List<Type>&& someList)
{
    someList.tail->SetNext(head);
    head = std::exchange(someList.head, nullptr);
    someList.tail = nullptr;
    csize += std::exchange(someList.csize, 0);
}

// template <CopyNMoveable Type>
// template <ConvertableForwardContainer<Type> C>
// void List<Type>::pushFront(const C& container)
// {
//     pushFront(List<Type>(container));
// }

template <CopyNMoveable Type>
template <std::ranges::input_range Range>
requires std::convertible_to<std::ranges::range_value_t<Range>, Type>
void List<Type>::pushFront(const Range& range)
{
    List<Type> list(range);
    list.pushBack(*this);
    *this = list;
}

template <CopyNMoveable Type>
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

template <CopyNMoveable Type>
template <Convertable<Type> T>
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

template <CopyNMoveable Type>
template <Convertable<Type> T>
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

template <CopyNMoveable Type>
void List<Type>::pushBack(List<Type>&& someList)
{
    tail->SetNext(std::exchange(someList.head, nullptr));
    tail = std::exchange(someList.tail, nullptr);
    csize += std::exchange(someList.csize, 0);
}

// template <CopyNMoveable Type>
// template <ConvertableForwardContainer<Type> C>
// void List<Type>::pushBack(const C& container)
// {
//     pushBack(List<Type>(container));
// }

template <CopyNMoveable Type>
template <std::ranges::input_range Range>
requires std::convertible_to<std::ranges::range_value_t<Range>, Type>
void List<Type>::pushBack(const Range& range)
{
    pushBack(List<Type>(range));
}

template <CopyNMoveable Type>
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

template <CopyNMoveable Type>
template <Convertable<Type> T>
typename List<Type>::iterator List<Type>::insert(const iterator &pos, const T& data)
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

template <CopyNMoveable Type>
template <Convertable<Type> T>
typename List<Type>::iterator List<Type>::insert(const iterator &pos, T&& data)
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

template <CopyNMoveable Type>
typename List<Type>::iterator List<Type>::insert(const iterator &pos, List<Type>&& someList)
{
    if (pos == cbegin())
    {
        pushFront(someList);
        return begin();
    }
    else if (pos == cend())
    {
        pushBack(someList);
        return iterator(tail);
    }
    else
    {
        auto currentNode = head;
        while (currentNode->GetNext() != pos.getNode())
        {
            currentNode = currentNode->GetNext();
        }
        someList.tail->SetNext(currentNode->GetNext());
        currentNode->SetNext(std::exchange(someList.head, nullptr));
        someList.tail = nullptr;
        csize += std::exchange(someList.csize, 0);
        return iterator(currentNode->GetNext());
    }
}

// template <CopyNMoveable Type>
// template <ConvertableForwardContainer<Type> C>
// typename List<Type>::iterator List<Type>::insert(const iterator &pos, const C &container)
// {
//     return insert(pos, List<Type>(container));
// }

template <CopyNMoveable Type>
template <std::ranges::input_range Range>
requires std::convertible_to<std::ranges::range_value_t<Range>, Type>
typename List<Type>::iterator List<Type>::insert(const iterator &pos, const Range& range)
{
    return insert(pos, List<Type>(range));
}

template <CopyNMoveable Type>
List<Type>& List<Type>::operator+=(List<Type> &&someList)
{
    pushBack(someList);
    return *this;
}

// template <CopyNMoveable Type>
// template <ConvertableForwardContainer<Type> C>
// List<Type>& List<Type>::operator+=(const C &container)
// {
//     pushBack(container);
//     return *this;
// }

template <CopyNMoveable Type>
template <Convertable<Type> T>
List<Type>& List<Type>::operator+=(const T &data)
{
    pushBack(data);
    return *this;
}

template <CopyNMoveable Type>
template <Convertable<Type> T>
List<Type>& List<Type>::operator+=(T &&data)
{
    pushBack(std::move(data));
    return *this;
}

template <CopyNMoveable Type>
template <std::ranges::input_range Range>
requires std::convertible_to<std::ranges::range_value_t<Range>, Type>
List<Type>& List<Type>::operator+=(const Range& range)
{
    List<Type> result(*this);
    result.pushBack(range);
    return result;
}

// template <CopyNMoveable Type>
// template <ConvertableForwardContainer<Type> C>
// List<Type> List<Type>::operator+(const C &container) const
// {
//     List<Type> result(*this);
//     result.pushBack(container);
//     return result;
// }

template <CopyNMoveable Type>
template <Convertable<Type> T>
List<Type> List<Type>::operator+(const T &data) const
{
    List<Type> result(*this);
    result.pushBack(data);
    return result;
}

template <CopyNMoveable Type>
template <Convertable<Type> T>
List<Type> List<Type>::operator+(T &&data) const
{
    List<Type> result(*this);
    result.pushBack(std::move(data));
    return result;
}

template <CopyNMoveable Type>
template <std::ranges::input_range Range>
requires std::convertible_to<std::ranges::range_value_t<Range>, Type>
List<Type> List<Type>::operator+(const Range& range)
{
    List<Type> result(*this);
    result.pushBack(range);
    return result;
}

template <CopyNMoveable Type, Convertable<Type> T>
List<Type> operator+(const T& value, const List<Type>& list)
{
    List<Type> result(list);
    result.pushFront(value);
    return result;
}

template <CopyNMoveable Type, Convertable<Type> T>
List<Type> operator+(T&& value, const List<Type>& list)
{
    List<Type> result(list);
    result.pushFront(std::move(value));
    return result;
}

template <CopyNMoveable Type>
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

template <CopyNMoveable Type>
void List<Type>::remove(iterator pos)
{
    validateListIterartor(pos, __LINE__);
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

template <CopyNMoveable Type>
void List<Type>::remove(iterator st, iterator end)
{
    validateListIterartorRange(st, end, __LINE__);
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

template <CopyNMoveable Type>
void List<Type>::remove(iterator st, size_type n)
{
    auto end = std::next(st, n);
    validateListIterartorRange(st, end, __LINE__);
    remove(st, end);
}

template <CopyNMoveable Type>
void List<Type>::clear() noexcept
{
    head.reset();
    tail.reset();
    csize = 0;
}

template <CopyNMoveable Type>
bool List<Type>::isEmpty() const noexcept
{
    return csize == 0;
}

template <CopyNMoveable Type>
void List<Type>::validateListIterartor(const ListIterator<Type> &iterator, size_t line)
{
    auto it = begin();
    for (; it != end() && it != iterator; ++it);
    if (it == end())
    {
        time_t t_time = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    }
}

template <CopyNMoveable Type>
void List<Type>::validateListIterartorRange(const ListIterator<Type> &begin, const ListIterator<Type> &end, size_t line)
{
    validateListIterartor(begin, line);
    validateListIterartor(end, line);
    auto it = this->begin();
    for (; it != end && it != begin; ++it);
    if (it == end)
    {
        time_t t_time = time(NULL);
        throw InvalidRange(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    }
}

template <CopyNMoveable T>
std::ostream& operator <<(std::ostream & os, const List<T> & list)
{
    std::for_each(list.cbegin(), list.cend(), [list](const T& elem){std::cout << elem << " ";});

	return os;
}
