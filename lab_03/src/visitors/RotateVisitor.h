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

#endif //_ROTATEVISITOR_H