#pragma once

#include <memory>
#include "list.h"
#include "__concepts.hpp"

template <CopyNMoveable Type>
class List;

template<CopyNMoveable Type>
class BaseIterator
{
public:
    friend class List<Type>;

    virtual ~BaseIterator() = default;
    bool IsValid() const noexcept;
    operator bool() const noexcept;

    bool operator==(const BaseIterator<Type>& other) const noexcept;
    bool operator!=(const BaseIterator<Type>& other) const noexcept;
protected:
    List<Type>::ListNode::node_ptr getNode() const;
    List<Type>::ListNode::node_wptr wptr;
};

#include "__base_iterator.hpp"
