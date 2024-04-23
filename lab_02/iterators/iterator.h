#pragma once

#include <memory>
#include "base_iterator.h"
#include "__concepts.hpp"

template <CopyNMoveable Type>
class List;

template <CopyNMoveable Type>
class ListIterator : public BaseIterator<Type>
{
public:
	friend class List<Type>;

	using iterator_category = std::forward_iterator_tag;

	using value_type = Type;
	using difference_type = std::ptrdiff_t;
	using pointer = std::shared_ptr<Type>;
	using reference = Type&;

	ListIterator() = default;
    ListIterator(const ListIterator<Type>& other);
	ListIterator<Type>& operator=(const ListIterator<Type>& other);

    ~ListIterator() = default;

    bool IsValid() const;

	reference operator*();
	const reference operator*() const;
	pointer operator->();
	const pointer operator->() const;
	operator bool() const;

	ListIterator<Type>& operator++();
	ListIterator<Type> operator++(int);

    bool operator==(const ListIterator<Type> &other) const;
    bool operator!=(const ListIterator<Type> &other) const;

protected:
    List<Type>::ListNode::node_ptr currentNode;

    void checkValid(size_t line) const;
    List<Type>::ListNode::node_ptr getNode() const;
    ListIterator(List<Type>::ListNode::node_ptr node);
};

#include "__iterator.hpp"
