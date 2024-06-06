/**
 * Project Untitled
 */


#ifndef _VISIBLEOBJECT_H
#define _VISIBLEOBJECT_H

#include "BaseObject.hpp"


class VisibleObject: public BaseObject{
public:
    VisibleObject();
    virtual ~VisibleObject() = 0;

    virtual bool IsVisible() const;
    virtual bool IsComposite() const;
};

#endif //_VISIBLEOBJECT_H
