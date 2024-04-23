#pragma once

#include <memory>
#include "iterator.h"
#include "const_iterator.h"
#include "concepts.h"
#include "base_list.h"

template <typename Type>
requires EqualityComparable<Type>
class List : public BaseList
{
public:
	using value_type = Type;
	using iterator = ListIterator<Type>;
	using const_iterator = ConstListIterator<Type>;
	using size_type = size_t;

	friend class ListIterator<Type>;
	friend class ConstListIterator<Type>;

	List() = default;
	explicit List(const List<Type>& someList);
	List(List<Type>&& someList) = default;
	explicit List(size_type n);

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	List(size_type n, const T& value);

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	List(std::initializer_list<T> initList);

	template <Container C>
	requires Convertable<typename C::value_type, typename List<Type>::value_type> &&
			 ForwardIterator<typename C::iterator>
	explicit List(const C& container);

	template <Container C>
	requires Convertable<typename C::value_type, typename List<Type>::value_type>
	List(C&& container);

	template <ForwardIterator Iter>
	requires Convertable<typename Iter::value_type, typename List<Type>::value_type>
	explicit List(const Iter& begin, const Iter& end);
	
	~List() override = default;

	size_type size() const noexcept;

	iterator begin() noexcept;
	const_iterator begin() const noexcept;
	const_iterator cbegin() const noexcept;
	
	iterator end() noexcept;
	const_iterator end() const noexcept;
	const_iterator cend() const noexcept;

	List<Type>& operator=(const List<Type>& someList);
	List<Type>& operator=(List<Type>&& someList);

	template <Container C>
	requires Convertable<typename C::value_type, typename List<Type>::value_type> &&
			 ForwardIterator<typename C::iterator>
	List<Type>& operator=(const C& container);

	template <Container C>
    requires Convertable<typename C::value_type, typename List<Type>::value_type>
	List<Type>& operator=(C&& container);

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	List<Type>& operator=(std::initializer_list<T> someList);

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	void pushFront(const T& data);

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	void pushFront(T&& data);

	void popFront() noexcept;

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	void pushBack(const T& data);

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	void pushBack(T&& data);

	void popBack() noexcept;

	iterator getFront();
	iterator getBack();
	const_iterator getFront() const;
	const_iterator getBack() const;

	iterator get(size_t index);
	const_iterator get(size_t index) const;

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	iterator insert(const_iterator pos, const T& data);

	template <typename T>
	requires Convertable<T, typename List<Type>::value_type>
	iterator insert(const_iterator pos, T&& data);

	template <Container C>
    requires Convertable<typename C::value_type, typename List<Type>::value_type> &&
             ForwardIterator<typename C::iterator>
	List<Type>& operator+=(const C &container);

	template <Container C>
    requires Convertable<typename C::value_type, typename List<Type>::value_type> &&
             ForwardIterator<typename C::iterator>
	List<Type>& operator+=(C &&container);

	template <typename T>
    requires Convertable<T, typename List<Type>::value_type>
	List<Type>& operator+=(const T &data);

	template <typename T>
    requires Convertable<T, typename List<Type>::value_type>
	List<Type>& operator+=(T &&data);

	template <Container C>
    requires Convertable<typename C::value_type, typename List<Type>::value_type> &&
             ForwardIterator<typename C::iterator>
	List<Type> operator+(const C &container) const;

	template <Container C>
    requires Convertable<typename C::value_type, typename List<Type>::value_type> &&
             ForwardIterator<typename C::iterator>
	List<Type> operator+(C &&container) const;

	template <typename T>
    requires Convertable<T, typename List<Type>::value_type>
	List<Type> operator+(const T &data) const;

	template <typename T>
    requires Convertable<T, typename List<Type>::value_type>
	List<Type> operator+(T &&data) const;

	void reverse() noexcept;

	void remove(const_iterator pos);

	void clear() noexcept;

	bool isEmpty() const noexcept;

	bool operator==(const List<Type>& someList) const;
	bool operator!=(const List<Type>& someList) const;

protected:
	class ListNode 
	{
	public:
		ListNode() = default;
		ListNode(const value_type &data);
		ListNode(value_type &&data);
		ListNode(const value_type &data, const std::shared_ptr<ListNode> &next);
		ListNode(value_type &&data, const std::shared_ptr<ListNode> &next);
		ListNode(const ListNode &node);
		ListNode(ListNode &&node) noexcept;
		~ListNode() = default;

		void SetNext(const std::shared_ptr<ListNode> &node);
		void SetData(const value_type &data);
		void SetData(value_type &&data);
		void SetNextNull();

		value_type &GetData();
		const value_type &GetData() const;
		std::shared_ptr<ListNode> GetNext() const;

		bool operator==(const ListNode &node) const;
		bool operator!=(const ListNode &node) const;
	
	protected:
		value_type data;
		std::shared_ptr<ListNode> next;
	};

protected:
	std::shared_ptr<ListNode> head = nullptr;
	std::shared_ptr<ListNode> tail = nullptr;
	size_t csize = 0;
};

template <typename Type, typename T>
requires Convertable<T, Type>
List<Type> operator+(const T& value, const List<Type>& container);

template <typename Type, typename T>
requires Convertable<T, Type>
List<Type> operator+(T&& value, const List<Type>& container);

#include "list.hpp"
#include "list_node.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"
