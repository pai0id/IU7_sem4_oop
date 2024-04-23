#pragma once

#include <memory>
#include "list.h"

template <typename Type>
template <typename... Args>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(Args&&... params)
{
    struct Enable_make_shared : public List<Type>::ListNode
    {
        Enable_make_shared(Args&&... params) : List<Type>::ListNode(std::forward<Args>(params)...) {}
    };

    return std::make_shared<Enable_make_shared>(std::forward<Args>(params)...);
}

template <typename Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::GetNext() const noexcept
{
    return next;
}

template <typename Type>
List<Type>::ListNode::data_ptr List<Type>::ListNode::GetData()
{
    List<Type>::ListNode::node_ptr work = this->shared_from_this();

    return { work, &work->data };
}

template <typename Type>
const List<Type>::ListNode::data_ptr List<Type>::ListNode::GetData() const
{
    List<Type>::ListNode::node_ptr work = this->shared_from_this();

    return { work, &work->data };
}

template <typename Type>
void List<Type>::ListNode::SetNext(node_ptr &node)
{
    next = node;
}

template <typename Type>
void List<Type>::ListNode::SetData(const value_type &data)
{
    this->data = data;
}

template <typename Type>
void List<Type>::ListNode::SetData(value_type &&data)
{
    this->data = std::move(data);
}

template <typename Type>
void List<Type>::ListNode::SetNextNull()
{
    next = nullptr;
}

template <typename Type>
List<Type>::ListNode::ListNode(value_type data, node_ptr next)
{
    this->data = data;
    this->next = next;
}
