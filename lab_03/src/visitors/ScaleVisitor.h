/**
 * Project Untitled
 */


#ifndef _SCALEVISITOR_H
#define _SCALEVISITOR_H

#include "Visitor.h"

class ScaleVisitor: public Visitor {
public: 
    
/**
 * @param Model
 */
void visit(BaseModel);
    
/**
 * @param Composite
 */
void visit(Composite);
};

#endif //_SCALEVISITOR_H
