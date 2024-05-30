/**
 * Project Untitled
 */


#ifndef _SCENEMEMENTOCARETAKER_H
#define _SCENEMEMENTOCARETAKER_H

#include "MementoCaretaker.h"


class SceneMementoCaretaker: public MementoCaretaker {
public: 
    
/**
 * @param Memento
 */
void add(Memento);
    
void get();
};

#endif //_SCENEMEMENTOCARETAKER_H
