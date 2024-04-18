#ifndef CONST_ITER_H
#define CONST_ITER_H

#include <memory>

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
	using pointer = const Type*;
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
    std::shared_ptr<typename List<Type>::ListNode> currentNode;

    void checkValid(size_t line) const;
    std::shared_ptr<typename List<Type>::ListNode> getNode() const;
    ConstListIterator(const std::shared_ptr<typename List<Type>::ListNode> &node);
};

#endif
