/**
 * Project Untitled
 */


#ifndef _BASEMODEL_H
#define _BASEMODEL_H

#include "VisibleObject.h"


class BaseModel: public VisibleObject {
public:
    BaseModel();
    virtual ~BaseModel() = 0;

    virtual void Accept(const Visitor &visitor) { (void) visitor; };
    virtual PtrBaseObject Clone() const { return nullptr;};
};

#endif //_BASEMODEL_H
