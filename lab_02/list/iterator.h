#ifndef ITER_H
#define ITER_H

#include <memory>

template <typename Type>
class List;

template <typename Type>
class ListIterator
{
public:
	friend class List<Type>;

	using iterator_category = std::forward_iterator_tag;

	using value_type = Type;
	using difference_type = std::ptrdiff_t;
	using pointer = Type*;
	using reference = Type&;

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

private:
    std::shared_ptr<typename List<Type>::ListNode> currentNode;

    void checkValid(size_t line) const;
    std::shared_ptr<typename List<Type>::ListNode> getNode() const;
    ListIterator(std::shared_ptr<typename List<Type>::ListNode>& node);
};

#endif
