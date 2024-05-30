/**
 * Project Untitled
 */


#ifndef _DRAWVISITOR_H
#define _DRAWVISITOR_H

#include "Visitor.h"

class DrawVisitor: public Visitor {
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
    
void getProjection();
};

#endif //_DRAWVISITOR_H
