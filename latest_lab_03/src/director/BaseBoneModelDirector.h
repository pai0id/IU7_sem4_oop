#pragma once
#include "BaseDirector.h"
#include "BaseBoneModelBuilder.h"
#include "BoneModelReader.h"

class BaseBoneModelDirector : public BaseDirector {
    public: 
        BaseBoneModelDirector(std::shared_ptr<BoneModelReader> reader);
        
        virtual ~BaseBoneModelDirector() = 0;
        
        virtual std::shared_ptr<Object> Create();

    protected:
        std::shared_ptr<BaseBoneModelBuilder> _builder;
        std::shared_ptr<BoneModelReader> _reader;
};
