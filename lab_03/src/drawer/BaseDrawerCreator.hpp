/**
 * Project Untitled
 */


#ifndef _BASEDRAWERCREATOR_H
#define _BASEDRAWERCREATOR_H

#include "BaseDrawer.hpp"
#include <memory>

class BaseDrawerCreator {
public:
    BaseDrawerCreator() = default;
    virtual ~BaseDrawerCreator() = 0;

    virtual std::shared_ptr<BaseDrawer> Create() = 0;
};

#endif //_BASEDRAWERCREATOR_H
