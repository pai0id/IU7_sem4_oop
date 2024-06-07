#pragma once
#include "BoneModel.h"
#include "ModelStructure.h"

#include "CenterStrategy.h"
#include "BoneModelReader.h"

class BaseBoneModelBuilder {
    public:
        BaseBoneModelBuilder() = default;

        virtual ~BaseBoneModelBuilder() = 0;

        virtual std::shared_ptr<BoneModel> Get();
        virtual void Build(std::shared_ptr<BoneModelReader>, std::shared_ptr<BaseCenterStrategy>);
        virtual bool IsBuilt();
    protected:
        std::shared_ptr<ModelStructure> _model;
};
