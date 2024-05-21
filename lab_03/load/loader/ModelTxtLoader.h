/**
 * Project Untitled
 */


#ifndef _MODELTXTLOADER_H
#define _MODELTXTLOADER_H

#include "BaseLoader.h"


class ModelTxtLoader: public BaseLoader {
public: 
    
void open();
    
void close();
    
void isOpen();
};

#endif //_MODELTXTLOADER_H