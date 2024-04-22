#pragma once

#include <memory>
#include "__concepts.hpp"

template <typename Type>
class List;

template <typename Type>
class ConstListIterator
{
public:
	friend class List<Type>;
	using iterator_category = std::forward_iterator_tag;

	using value_type = Type;
	using difference_type = std::ptrdiff_t;
	using pointer = const std::shared_ptr<Type>;
	using reference = const Type&;

    ConstListIterator(const ConstListIterator<Type>& other);
	ConstListIterator<Type> operator=(const ConstListIterator<Type> &other);

    ~ConstListIterator() = default;

    bool IsValid() const;

	reference operator*() const;
	pointer operator->() const;
	operator bool() const;

	ConstListIterator<Type>& operator++();
	ConstListIterator<Type> operator++(int);

    bool operator==(const ConstListIterator<Type> &other) const;
    bool operator!=(const ConstListIterator<Type> &other) const;

private:
    List<Type>::ListNode::node_ptr currentNode;

    void checkValid(size_t line) const;
    List<Type>::ListNode::node_ptr getNode() const;
    ConstListIterator(const List<Type>::ListNode::node_ptr node);
};
