#pragma once

#include <memory>
#include "base_list.h"
#include "iterator.h"
#include "const_iterator.h"
#include "range.h"
#include "__concepts.hpp"

template <typename Type>
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

	template <typename T>
	requires Convertible<T, Type>
	List(size_type n, const T& value);

	template <typename T>
	requires Convertible<T, Type>
	List(std::initializer_list<T> initList);

	template <Container C>
	requires Convertible<typename C::value_type, Type> &&
			 InputIterator<typename C::iterator>
	explicit List(const C& container);

	template <Container C>
	requires Convertible<typename C::value_type, Type> &&
			 InputIterator<typename C::iterator>
	List(C&& container);

	template <InputIterator Iter>
	requires Convertible<typename Iter::value_type, Type>
	explicit List(const Iter& begin, const Iter& end);

	template <InputIterator Iter>
	requires Convertible<typename Iter::value_type, Type>
	explicit List(Range<Iter> range);

	template <InputIterator Iter>
	requires Convertible<typename Iter::value_type, Type>
	explicit List(const Iter& begin, const size_t size);
	
	~List() override = default;

	List<Type>& operator=(const List<Type>& someList);
	List<Type>& operator=(List<Type>&& someList);

	template <Container C>
	requires Convertible<typename C::value_type, Type> &&
			 InputIterator<typename C::iterator>
	List<Type>& operator=(const C& container);

	template <Container C>
    requires Convertible<typename C::value_type, Type> &&
			 InputIterator<typename C::iterator>
	List<Type>& operator=(C&& container);

	template <typename T>
	requires Convertible<T, Type>
	List<Type>& operator=(std::initializer_list<T> someList);

	size_type size() const noexcept;

	iterator begin() noexcept;
	const_iterator begin() const noexcept;
	const_iterator cbegin() const noexcept;
	
	iterator end() noexcept;
	const_iterator end() const noexcept;
	const_iterator cend() const noexcept;

	iterator getFront();
	iterator getBack();
	const_iterator getFront() const;
	const_iterator getBack() const;

	template <typename T>
	requires Convertible<T, Type>
	void pushFront(const T& data);

	template <typename T>
	requires Convertible<T, Type>
	void pushFront(T&& data);

	void popFront() noexcept;

	template <typename T>
	requires Convertible<T, Type>
	void pushBack(const T& data);

	template <typename T>
	requires Convertible<T, Type>
	void pushBack(T&& data);

	void popBack() noexcept;

	template <typename T>
	requires Convertible<T, Type>
	iterator insert(const_iterator pos, const T& data);

	template <typename T>
	requires Convertible<T, Type>
	iterator insert(const_iterator pos, T&& data);

	template <Container C>
    requires Convertible<typename C::value_type, Type> &&
             InputIterator<typename C::iterator>
	List<Type>& operator+=(const C &container);

	template <Container C>
    requires Convertible<typename C::value_type, Type> &&
             InputIterator<typename C::iterator>
	List<Type>& operator+=(C &&container);

	template <typename T>
    requires Convertible<T, Type>
	List<Type>& operator+=(const T &data);

	template <typename T>
    requires Convertible<T, Type>
	List<Type>& operator+=(T &&data);

	template <Container C>
    requires Convertible<typename C::value_type, Type> &&
             InputIterator<typename C::iterator>
	List<Type> operator+(const C &container) const;

	template <Container C>
    requires Convertible<typename C::value_type, Type> &&
             InputIterator<typename C::iterator>
	List<Type> operator+(C &&container) const;

	template <typename T>
    requires Convertible<T, Type>
	List<Type> operator+(const T &data) const;

	template <typename T>
    requires Convertible<T, Type>
	List<Type> operator+(T &&data) const;

	void reverse() noexcept;

	void remove(const_iterator pos);
	// void remove(const_iterator st, const_iterator end);
	// void remove(const_iterator st, size_type n);
	// void remove(Range<const_iterator> range);

	void clear() noexcept;

	bool isEmpty() const noexcept;

protected:
	class ListNode : public std::enable_shared_from_this<List<Type>::ListNode>
	{
	public:
		using node_ptr = std::shared_ptr<ListNode>;
		using data_ptr = std::shared_ptr<value_type>;

		ListNode() = delete;
		ListNode(const ListNode&) = delete;
		ListNode(ListNode&&) = delete;

		template <typename... Args>
    	static node_ptr initNode(Args&&... params);
		~ListNode() = default;

		node_ptr GetNext() const noexcept;
    	data_ptr GetData();
    	const data_ptr GetData() const;

		void SetNext(node_ptr &node);
		void SetData(const value_type &data);
		void SetData(value_type &&data);
		void SetNextNull();
	
	private:
		value_type data;
		node_ptr next = nullptr;

		ListNode(value_type data, node_ptr next);
	};

private:
	ListNode::node_ptr head = nullptr;
	ListNode::node_ptr tail = nullptr;
	size_t csize = 0;
};

template <typename Type, typename T>
requires Convertible<T, Type>
List<Type> operator+(const T& value, const List<Type>& container);

template <typename Type, typename T>
requires Convertible<T, Type>
List<Type> operator+(T&& value, const List<Type>& container);

template <typename T>
std::ostream& operator <<(std::ostream & os, const List<T> & list);

#include "__list.hpp"
#include "__list_node.hpp"
