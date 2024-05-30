/**
 * Project Untitled
 */


#ifndef _VISITOR_H
#define _VISITOR_H

#include "../scene/BaseModel.h"
#include "../scene/Composite.h"
#include "../scene/Camera.h"

class Visitor {
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

#endif //_VISITOR_H
