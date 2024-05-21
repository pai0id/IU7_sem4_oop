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
void visit(void Model);
    
/**
 * @param Composite
 */
void visit(void Composite);
    
/**
 * @param Camera
 */
void visit(void Camera);
};

#endif //_MOVEVISITOR_H