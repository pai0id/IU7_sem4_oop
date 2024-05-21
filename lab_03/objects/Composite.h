/**
 * Project Untitled
 */


#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "BaseObject.h"


class Composite: public BaseObject {
public: 
    
void add();
    
void remove();
    
void isComposite();
    
void begin();
    
void end();
    
void accept();
};

#endif //_COMPOSITE_H