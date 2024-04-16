#ifndef _BASELIST_H_
#define _BASELIST_H_

#include <cstddef>

class ListBase
{
public:
    virtual size_t size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~ListBase() = default;
};

#endif // _BASELIST_H_