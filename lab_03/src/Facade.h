#ifndef _FACADE_H
#define _FACADE_H

#include "commands/BaseCommand.h"

class Facade {
public: 
    
void execute(BaseCommand &command);
};

#endif //_FACADE_H
