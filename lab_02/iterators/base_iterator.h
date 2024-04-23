#pragma once

template<typename Type>
class BaseIterator
{
public:
    virtual ~BaseIterator() = default;

    bool IsValid() const noexcept;
    operator bool() const noexcept;

    bool operator==(const BaseIterator<Type>& other) const noexcept;
    bool operator!=(const BaseIterator<Type>& other) const noexcept;
};