/**
 * Project Untitled
 */


#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "BaseObject.h"

class Composite: public BaseObject {
private:
    VectorBaseObject _objects;

public:
    Composite() = default;
    Composite(PtrBaseObject first, ...);
    Composite(VectorBaseObject objects);

    virtual ~Composite() = default;
    virtual void Add(const PtrBaseObject object);
    virtual void Remove(const iterator &it);
    virtual bool IsComposite() const;
    virtual bool IsVisible() const;
    virtual Point GetCenter() const;
    virtual iterator begin();
    virtual iterator end();

    virtual void Accept(const Visitor &v);
};

#endif //_COMPOSITE_H
