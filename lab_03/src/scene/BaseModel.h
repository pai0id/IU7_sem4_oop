/**
 * Project Untitled
 */


#ifndef _BASEMODEL_H
#define _BASEMODEL_H

#include "VisibleObject.h"


class BaseModel: public VisibleObject {
public: 
    
void accept();
    
void isComposite();
};

#endif //_BASEMODEL_H