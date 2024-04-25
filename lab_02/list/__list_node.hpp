#pragma once

#include <memory>
#include "list.h"

template <CopyNMoveable Type>
template <typename... Args>
List<Type>::ListNode::node_ptr List<Type>::ListNode::initNode(Args&&... params)
{
    struct Enable_make_shared : public List<Type>::ListNode
    {
        Enable_make_shared(Args&&... params) : List<Type>::ListNode(std::forward<Args>(params)...) {}
    };

    return std::make_shared<Enable_make_shared>(std::forward<Args>(params)...);
}

template <CopyNMoveable Type>
List<Type>::ListNode::node_ptr List<Type>::ListNode::GetNext() const noexcept
{
    return next;
}

template <CopyNMoveable Type>
List<Type>::ListNode::data_ptr List<Type>::ListNode::GetData()
{
    List<Type>::ListNode::node_ptr work = this->shared_from_this();

    return { work, &work->data };
}

template <CopyNMoveable Type>
const List<Type>::ListNode::data_ptr List<Type>::ListNode::GetData() const
{
    List<Type>::ListNode::node_ptr work = this->shared_from_this();

    return { work, &work->data };
}

template <CopyNMoveable Type>
void List<Type>::ListNode::SetNext(const node_ptr &node)
{
    next = node;
}

template <CopyNMoveable Type>
void List<Type>::ListNode::SetData(const value_type &data)
{
    this->data = data;
}

template <CopyNMoveable Type>
void List<Type>::ListNode::SetData(value_type &&data)
{
    this->data = std::move(data);
}

template <CopyNMoveable Type>
void List<Type>::ListNode::SetNextNull()
{
    next = nullptr;
}

template <CopyNMoveable Type>
List<Type>::ListNode::ListNode(value_type d, node_ptr n): data(d), next(n) {}
