#pragma once
#include "BoneModel.h"
#include "ModelStructure.h"
#include "BoneModelReader.h"

class BaseBoneModelBuilder {
    public:
        BaseBoneModelBuilder() = default;

        virtual ~BaseBoneModelBuilder() = 0;

        virtual std::shared_ptr<BoneModel> Get();
        virtual void Build(std::shared_ptr<BoneModelReader>);
        virtual bool IsBuilt();
    protected:
        std::shared_ptr<ModelStructure> _model;
};
