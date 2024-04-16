/*Класс итератор*/
#ifndef _LISTITERATOR_H_
#define _LISTITERATOR_H_

#include "listnode.h"
#include <string>
#include <memory>
#include "errors.h"


template <typename T>
class IteratorBase : public std::iterator<std::input_iterator_tag, T>
{
protected:
    std::weak_ptr<ListNode<T>> ptrCur;
public:
    
    IteratorBase();
    IteratorBase(const IteratorBase<T>& listIter);
    explicit IteratorBase(const std::shared_ptr<ListNode<T>> node);
    
    virtual ~IteratorBase() = default;

    
    IteratorBase<T>& operator=(const IteratorBase<T>& listIter);

    IteratorBase<T>& next();
    IteratorBase<T>& operator++();
    IteratorBase<T> operator++(int);

    bool checkRange() const;

    bool operator==(const IteratorBase<T>& listIter) const;
    bool operator!=(const IteratorBase<T>& listIter) const;
};


template <typename T>
class Iterator : public IteratorBase<T>
{
public:
    
    Iterator();
    Iterator(const Iterator<T>& listIter);
    Iterator(const std::shared_ptr<ListNode<T>> node);

    
    Iterator<T>& operator=(const Iterator<T>& listIter);

    T& getCur();
    const T& getCur() const;

    T& getNext();
    const T& getNext() const;

    T& operator*();
    const T& operator*() const;

    T* operator->();
    const T* operator->() const;

    operator bool() const noexcept; 
};

#endif
