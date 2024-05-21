/**
 * Project Untitled
 */


#ifndef _LINKDOTLOADDIRECTOR_H
#define _LINKDOTLOADDIRECTOR_H

#include "BaseLoadDirector.h"
#include "BaseCarcasLoadDirector.h"


class LinkDotLoadDirector: public BaseLoadDirector, public BaseCarcasLoadDirector {
public: 
    
void create();
};

#endif //_LINKDOTLOADDIRECTOR_H