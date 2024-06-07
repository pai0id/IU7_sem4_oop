/**
 * Project Untitled
 */


#ifndef _BASEMODEL_H
#define _BASEMODEL_H

#include "VisibleObject.hpp"

class BaseModel : public VisibleObject {
public:
    BaseModel();
    virtual ~BaseModel() = 0;

    virtual void Accept(std::shared_ptr<Visitor> v);
    virtual PtrBaseObject Clone() const { return nullptr;};
};

#endif //_BASEMODEL_H
