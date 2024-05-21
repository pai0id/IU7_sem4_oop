/**
 * Project Untitled
 */


#ifndef _SCENESVGLOADER_H
#define _SCENESVGLOADER_H

#include "BaseLoader.h"


class SceneSvgLoader: public BaseLoader {
public: 
    
void open();
    
void close();
    
void isOpen();
};

#endif //_SCENESVGLOADER_H