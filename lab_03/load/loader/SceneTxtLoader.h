/**
 * Project Untitled
 */


#ifndef _SCENETXTLOADER_H
#define _SCENETXTLOADER_H

#include "BaseLoader.h"


class SceneTxtLoader: public BaseLoader {
public: 
    
void open();
    
void close();
    
void isOpen();
};

#endif //_SCENETXTLOADER_H