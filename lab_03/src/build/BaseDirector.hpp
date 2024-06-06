#ifndef _BASEDIRECTOR_H
#define _BASEDIRECTOR_H

#include "../scene/BaseObject.hpp"

class BaseDirector {
public:
    BaseDirector() = default;

    virtual ~BaseDirector() = 0;

    virtual void Create() = 0;
    virtual std::shared_ptr<BaseObject> Get() = 0;
};

#endif
