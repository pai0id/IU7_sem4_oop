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

	// Конструкторы =============================

	List() = default;
	explicit List(const List<Type>& someList);
	List(List<Type>&& someList) = default;

	template <Convertable<Type> T>
	List(size_type n, const T& value);

	template <Convertable<Type> T>
	List(std::initializer_list<T> initList);

	template <ConvertableForwardContainer<Type> C>
	explicit List(const C& container);

	template <ConvertableForwardContainer<Type> C>
	List(C&& container);

	template <ConvertableForwardIterator<Type> I>
	explicit List(const I& begin, const I& end);

	template <ConvertableForwardIterator<Type> I>
	explicit List(const I& begin, const size_t size);

	template <ConvertableForwardIterator<Type> I>
	explicit List(Range<I> range);

	// ~Конструкторы ============================
	
	// Деструктор
	~List() override = default;
	
	// Операторы присваивания ===================

	List<Type>& operator=(const List<Type>& someList);
	List<Type>& operator=(List<Type>&& someList);

	template <ConvertableForwardContainer<Type> C>
	List<Type>& operator=(const C& container);

	template <ConvertableForwardContainer<Type> C>
	List<Type>& operator=(C&& container);

	template <Convertable<Type> T>
	List<Type>& operator=(std::initializer_list<T> someList);

	template <ConvertableForwardIterator<Type> I>
	List<Type>& operator=(Range<I> range);

	// ~Операторы присваивания ==================

	// Размер
	size_type size() const noexcept;
	bool isEmpty() const noexcept;

	// Получение позиций ========================

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

	// ~Получение позиций =======================

	// Добавление ===============================

	template <Convertable<Type> T>
	void pushFront(const T& data);

	template <Convertable<Type> T>
	void pushFront(T&& data);

	template <Convertable<Type> T>
	void pushBack(const T& data);

	template <Convertable<Type> T>
	void pushBack(T&& data);

	template <Convertable<Type> T>
	iterator insert(const_iterator pos, const T& data);

	template <Convertable<Type> T>
	iterator insert(const_iterator pos, T&& data);

	template <ConvertableForwardContainer<Type> C>
	List<Type>& operator+=(const C &container);

	template <ConvertableForwardContainer<Type> C>
	List<Type>& operator+=(C &&container);

	template <Convertable<Type> T>
	List<Type>& operator+=(const T &data);

	template <Convertable<Type> T>
	List<Type>& operator+=(T &&data);

	template <ConvertableForwardContainer<Type> C>
	List<Type> operator+(const C &container) const;

	template <ConvertableForwardContainer<Type> C>
	List<Type> operator+(C &&container) const;

	template <Convertable<Type> T>
	List<Type> operator+(const T &data) const;

	template <Convertable<Type> T>
	List<Type> operator+(T &&data) const;

	// ~Добавление ==============================

	// Удаление =================================

	void popFront() noexcept;

	void popBack() noexcept;

	void remove(const_iterator pos);
	void remove(const_iterator st, const_iterator end);
	void remove(const_iterator st, size_type n);

	void clear() noexcept;

	// ~Удаление =================================

	// Инвертирование
	void reverse() noexcept;

protected:
	// Узел списка
	class ListNode : public std::enable_shared_from_this<List<Type>::ListNode>
	{
	public:
		using node_ptr = std::shared_ptr<ListNode>;
		using data_ptr = std::shared_ptr<value_type>;

		// Создание =============================

		ListNode() = delete;
		ListNode(const ListNode&) = delete;
		ListNode(ListNode&&) = delete;

		template <typename... Args>
    	static node_ptr initNode(Args&&... params);
		~ListNode() = default;

		// ~Создание ============================

		// Получение ===========================

		node_ptr GetNext() const noexcept;
    	data_ptr GetData();
    	const data_ptr GetData() const;

		// ~Получение ==========================

		// Установка ===========================

		void SetNext(node_ptr &node);
		void SetData(const value_type &data);
		void SetData(value_type &&data);
		void SetNextNull();

		// ~Установка ==========================
	
	private:
		// Данные
		value_type data;
		node_ptr next = nullptr;

		ListNode(value_type data, node_ptr next);
	};

	// Проверки ==========================

	void validateListIterartor(const ListIterator<Type> &iterator, size_t line);
	void validateListIterartorRange(const ListIterator<Type> &begin, const ListIterator<Type> &end, size_t line);

	template <ConvertableForwardIterator<Type> I>
	void validateAnyIterartorRange(const I &begin, const I &end, size_t line);

	// ~Проверки =========================

private:
    // Данные
	ListNode::node_ptr head = nullptr;
	ListNode::node_ptr tail = nullptr;
	size_t csize = 0;
};

// Операторы сложения данных со списком

template <typename Type, Convertable<Type> T>
List<Type> operator+(const T& value, const List<Type>& container);

template <typename Type, Convertable<Type> T>
List<Type> operator+(T&& value, const List<Type>& container);

// Вывод

template <typename Type>
std::ostream& operator <<(std::ostream & os, const List<Type> & list);

#include "__list.hpp"
#include "__list_node.hpp"
