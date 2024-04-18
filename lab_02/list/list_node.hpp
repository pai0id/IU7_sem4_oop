#ifndef LIST_NODE_IMPL
#define LIST_NODE_IMPL

#include <memory>
#include "list.h"

template <typename Type>
List<Type>::ListNode::ListNode(const typename List<Type>::value_type &data) noexcept : data(data), next(nullptr) {}

template <typename Type>
List<Type>::ListNode::ListNode(typename List<Type>::value_type &&data) noexcept : data(std::move(data)), next(nullptr) {}

template <typename Type>
List<Type>::ListNode::ListNode(const typename List<Type>::value_type &data, const std::shared_ptr<ListNode> &next) noexcept : data(data), next(next) {}

template <typename Type>
List<Type>::ListNode::ListNode(typename List<Type>::value_type &&data, const std::shared_ptr<ListNode> &next) noexcept : data(std::move(data)), next(next) {}

template <typename Type>
List<Type>::ListNode::ListNode(const ListNode &node) noexcept : data(node.data), next(node.next) {}

template <typename Type>
List<Type>::ListNode::ListNode(ListNode &&node) noexcept : data(std::move(node.data)), next(std::move(node.next)) {}

template <typename Type>
void List<Type>::ListNode::SetNext(const std::shared_ptr<ListNode> &node) {
    next = node;
}

template <typename Type>
void List<Type>::ListNode::SetData(const typename List<Type>::value_type &data) {
    this->data = data;
}

template <typename Type>
void List<Type>::ListNode::SetData(typename List<Type>::value_type &&data) {
    this->data = std::move(data);
}

template <typename Type>
void List<Type>::ListNode::SetNextNull() {
    next = nullptr;
}

template <typename Type>
typename List<Type>::value_type& List<Type>::ListNode::GetData() {
    return data;
}

template <typename Type>
const typename List<Type>::value_type& List<Type>::ListNode::GetData() const {
    return data;
}

template <typename Type>
std::shared_ptr<typename List<Type>::ListNode> List<Type>::ListNode::GetNext() const {
    return next;
}

template <typename Type>
bool List<Type>::ListNode::operator==(const ListNode &node) const {
    return data == node.data && next == node.next;
}

template <typename Type>
bool List<Type>::ListNode::operator!=(const ListNode &node) const {
    return !(*this == node);
}

#endif
