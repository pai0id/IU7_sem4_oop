#ifndef _BASECARCMODELDIRECTOR_H
#define _BASECARCMODELDIRECTOR_H

#include "BaseDirector.hpp"
#include "BaseCarcasModelBuilder.hpp"
#include "../scene/CenterStrategy.hpp"
#include "../loader/CarcasModelLoader.hpp"

class BaseCarcasModelDirector : public BaseDirector {
public:
    BaseCarcasModelDirector(std::shared_ptr<CarcasModelLoader> Loader);

    virtual ~BaseCarcasModelDirector() = 0;

    virtual void Create();
    virtual std::shared_ptr<BaseObject> Get();

protected:
    std::shared_ptr<BaseCarcasModelBuilder> _builder;
    std::shared_ptr<BaseCenterStrategy> _strategy;
    std::shared_ptr<CarcasModelLoader> _Loader;
};

#endif
