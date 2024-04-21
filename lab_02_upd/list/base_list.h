#pragma once

class BaseList
{
public:
    virtual ~BaseList() = default;
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;
};
