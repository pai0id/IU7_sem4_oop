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
void visit(void Model);
    
/**
 * @param Composite
 */
void visit(void Composite);
    
/**
 * @param Camera
 */
void visit(void Camera);
    
void getProjection();
};

#endif //_DRAWVISITOR_H