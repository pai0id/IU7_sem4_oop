/**
 * Project Untitled
 */


#ifndef _ROTATEVISITOR_H
#define _ROTATEVISITOR_H

#include "Visitor.h"

class RotateVisitor: public Visitor {
public: 
    
/**
 * @param Model
 */
void visit(BaseModel);
    
/**
 * @param Composite
 */
void visit(Composite);
    
/**
 * @param Camera
 */
void visit(Camera);
};

#endif //_ROTATEVISITOR_H
