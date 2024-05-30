/**
 * Project Untitled
 */


#ifndef _MOVEVISITOR_H
#define _MOVEVISITOR_H

#include "Visitor.h"

class MoveVisitor: public Visitor {
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

#endif //_MOVEVISITOR_H
