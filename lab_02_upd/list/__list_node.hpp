#pragma once

#include <memory>
#include "list.h"

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(const value_type &data)
{
    auto node = std::make_shared<ListNode>();
    node->data = data;
    node->next = nullptr;
    return node;
}

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(value_type &&data)
{
    auto node = std::make_shared<ListNode>();
    node->data = std::move(data);
    node->next = nullptr;
    return node;
}

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(const value_type &data, const node_ptr &next)
{
    auto node = std::make_shared<ListNode>();
    node->data = data;
    node->next = next;
    return node;
}

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(value_type &&data, const node_ptr &next)
{
    auto node = std::make_shared<ListNode>();
    node->data = std::move(data);
    node->next = next;
    return node;
}

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(const ListNode &node)
{
    auto newNode = std::make_shared<ListNode>();
    newNode->data = node.data;
    newNode->next = node.next;
    return newNode;
}

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(ListNode &&node)
{
    auto newNode = std::make_shared<ListNode>();
    newNode->data = std::move(node.data);
    newNode->next = std::move(node.next);
    return newNode;
}

template <typename Type>
void List<Type>::ListNode::SetNext(const node_ptr &node)
{
    next = node;
}

template <typename Type>
void List<Type>::ListNode::SetData(const typename List<Type>::value_type &data)
{
    this->data = data;
}

template <typename Type>
void List<Type>::ListNode::SetData(typename List<Type>::value_type &&data)
{
    this->data = std::move(data);
}

template <typename Type>
void List<Type>::ListNode::SetNextNull()
{
    next = nullptr;
}

template <typename Type>
List<Type>::ListNode::data_ptr List<Type>::ListNode::GetData()
{
    return std::shared_ptr<List::value_type>(ListNode::node_ptr(), &this->data);
}

template <typename Type>
const List<Type>::ListNode::data_ptr List<Type>::ListNode::GetData() const
{
    return std::shared_ptr<List::value_type>(ListNode::node_ptr(), &this->data);
}

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::GetNext() const
{
    return next;
}
