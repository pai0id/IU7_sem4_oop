/**
 * Project Untitled
 */


#ifndef _SCENEMEMENTO_H
#define _SCENEMEMENTO_H

#include "Memento.h"


class SceneMemento: public Memento {
public: 
    
void getState();
    
/**
 * @param BaseObject
 */
void setState(void BaseObject);
};

#endif //_SCENEMEMENTO_H