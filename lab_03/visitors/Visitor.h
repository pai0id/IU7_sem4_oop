/**
 * Project Untitled
 */


#ifndef _VISITOR_H
#define _VISITOR_H

class Visitor {
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

#endif //_VISITOR_H