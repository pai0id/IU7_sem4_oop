/**
 * Project Untitled
 */


#ifndef _INVISIBLEOBJECT_H
#define _INVISIBLEOBJECT_H

#include "BaseObject.h"


class InvisibleObject: public BaseObject {
public:
    InvisibleObject();
    virtual ~InvisibleObject() = 0;

    virtual bool IsVisible() const;
    virtual bool IsComposite() const;
};

#endif //_INVISIBLEOBJECT_H
