#pragma once

#include <memory>
#include "base_iterator.h"
#include "iterator.h"
#include "__concepts.hpp"

template <CopyNMoveable Type>
class List;

template <CopyNMoveable Type>
class ListIterator;

template <CopyNMoveable Type>
class ConstListIterator : public BaseIterator<Type>
{
public:
	friend class List<Type>;
	friend class ListIterator<Type>;

	using iterator_category = std::forward_iterator_tag;

	using value_type = Type;
	using difference_type = std::ptrdiff_t;
	using pointer = const std::shared_ptr<Type>;
	using reference = const Type&;

	ConstListIterator() = default;
    ConstListIterator(const ConstListIterator<Type>& other);
	ConstListIterator<Type> operator=(const ConstListIterator<Type> &other);
    ConstListIterator(const ListIterator<Type>& other);
	ConstListIterator<Type> operator=(const ListIterator<Type> &other);


    ~ConstListIterator() = default;

    bool IsValid() const noexcept;

	reference operator*() const;
	pointer operator->() const;
	operator bool() const;

	ConstListIterator<Type>& operator++();
	ConstListIterator<Type> operator++(int);

    bool operator==(const ConstListIterator<Type> &other) const;
    bool operator!=(const ConstListIterator<Type> &other) const;

protected:
	List<Type>::ListNode::node_wptr wptr;

    List<Type>::ListNode::node_ptr getNode() const;
    ConstListIterator(const List<Type>::ListNode::node_ptr node);
};

#include "__const_iterator.hpp"
