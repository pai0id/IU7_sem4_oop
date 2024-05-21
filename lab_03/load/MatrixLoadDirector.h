/**
 * Project Untitled
 */


#ifndef _MATRIXLOADDIRECTOR_H
#define _MATRIXLOADDIRECTOR_H

#include "BaseLoadDirector.h"
#include "BaseCarcasLoadDirector.h"


class MatrixLoadDirector: public BaseLoadDirector, public BaseCarcasLoadDirector {
public: 
    
void create();
};

#endif //_MATRIXLOADDIRECTOR_H