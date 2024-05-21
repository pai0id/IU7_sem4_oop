/**
 * Project Untitled
 */


#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "BaseManager.h"


class SceneManager: public BaseManager {
public: 
    
void setScene();
    
void setCamera();
    
void removeCamera();
};

#endif //_SCENEMANAGER_H