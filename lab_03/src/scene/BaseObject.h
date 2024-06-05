/**
 * Project Untitled
 */


#ifndef _BASEOBJECT_H
#define _BASEOBJECT_H

#include "Point.h"
#include "../visitors/Visitor.h"
#include <memory>
#include <vector>
#include <cstddef>

size_t GetNextId();

class BaseObject;

using PtrBaseObject = std::shared_ptr<BaseObject>;
using VectorBaseObject = std::vector<PtrBaseObject>;

class BaseObject {
public:
    using value_type = BaseObject;
    using size_type = size_t;
    using iterator = VectorBaseObject::const_iterator;
    using const_iterator = VectorBaseObject::const_iterator;

    BaseObject();
    virtual ~BaseObject() = default;

    virtual bool IsComposite() const { return false; }
    virtual bool Add(std::initializer_list<PtrBaseObject> comp) { return false; }
    virtual bool Remove(const iterator& it) { return false; }
    virtual iterator Begin() const { return iterator(); }
    virtual iterator End() const { return iterator(); }

    virtual Point GetCenter() const = 0;
    virtual bool IsVisible() const = 0;

    virtual void Accept(const Visitor &visitor) { (void) visitor; };
    virtual size_t GetId() const { return _id; };
protected:
    size_t _id = 0;
};

#endif //_BASEOBJECT_H
