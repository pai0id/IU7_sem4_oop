/**
 * Project Untitled
 */


#ifndef _VISIBLEOBJECT_H
#define _VISIBLEOBJECT_H

#include "BaseObject.hpp"

class VisibleObject : public BaseObject {
public:
    VisibleObject();
    virtual ~VisibleObject() = 0;

    virtual bool IsVisible() const;
    virtual bool IsComposite() const;

    virtual void Accept(std::shared_ptr<Visitor> v) = 0;
};

#endif //_VISIBLEOBJECT_H
