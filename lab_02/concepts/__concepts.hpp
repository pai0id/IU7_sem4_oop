#pragma once

#include <concepts>
#include <iterator>

template <typename T1, typename T2>
concept Convertable = requires(T1 t1){ T2(t1);} &&
                      requires(T2 t2){ T1(t2);};

template<typename T>
concept CopyNMoveable = std::copyable<T> && std::movable<T>;

template<typename T>
concept EqualityComparable = requires(T a, T b)
{
    { a == b } -> std::same_as<bool>;
    { a != b } -> std::same_as<bool>;
};

template <typename T, typename U>
concept DerivedFrom = std::is_base_of<U, T>::value;

template <typename I>
concept Iterator = requires()
{
    typename I::value_type;
    typename I::difference_type;
    typename I::pointer;
    typename I::reference;
};

# pragma region Input_Iterator
template <typename I>
concept InputIterator = Iterator<I> &&
requires { typename I::iterator_category; }&&
EqualityComparable<I>&&
DerivedFrom<typename I::iterator_category, std::input_iterator_tag>;

# pragma endregion

# pragma region Forward_Iterator
template <typename I>
concept Incrementable = requires(I it)
{
    { ++it } -> std::same_as<I&>;
    { it++ } -> std::same_as<I>;
};

template <typename I>
concept ForwardIterator = InputIterator<I> &&
                          Incrementable<I> &&
                          DerivedFrom<typename I::iterator_category, std::forward_iterator_tag>;

template <typename I, typename T>
concept ConvertableForwardIterator = ForwardIterator<I> &&
                                     Convertable<typename I::value_type, T>;

# pragma endregion

# pragma region Container
template <typename Type>
concept Container = requires(Type t)
{
	typename Type::value_type;
	typename Type::size_type;
	typename Type::iterator;
	typename Type::const_iterator;

	{ t.size() } noexcept -> std::same_as<typename Type::size_type>;
	{ t.end() } noexcept -> std::same_as<typename Type::iterator>;
	{ t.begin() } noexcept -> std::same_as<typename Type::iterator>;
};

template <typename C, typename T>
concept ConvertableForwardContainer = Container<C> &&
                                     Convertable<typename C::value_type, T> &&
                                     ForwardIterator<typename C::iterator>;

# pragma endregion
