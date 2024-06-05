/**
 * Project Untitled
 */


#ifndef _VISITOR_H
#define _VISITOR_H

#include "../scene/BaseModel.h"
#include "../scene/Composite.h"
#include "../scene/Camera.h"

class Visitor
{
public:
    Visitor();

    virtual ~Visitor() {};
    virtual void Visit(BaseModel& model) const = 0;
    virtual void Visit(Composite& composite) const = 0;
    virtual void Visit(Camera& camera) const = 0;
};

#endif //_VISITOR_H
