#ifndef _INVISIBLEOBJECT_H
#define _INVISIBLEOBJECT_H

#include "BaseObject.hpp"

class InvisibleObject : public BaseObject {
public:
    InvisibleObject();
    virtual ~InvisibleObject() = 0;

    virtual bool IsVisible() const;
    virtual bool IsComposite() const;

    virtual void Accept(std::shared_ptr<Visitor> v) = 0;
};

#endif //_INVISIBLEOBJECT_H
