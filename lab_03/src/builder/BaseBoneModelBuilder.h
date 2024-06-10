#pragma once
#include "BoneModel.h"
#include "ModelStructure.h"
#include "BoneModelReader.h"

class BaseBoneModelBuilder {
    public:
        BaseBoneModelBuilder();
        explicit BaseBoneModelBuilder(std::shared_ptr<BoneModelReader> reader);
        ~BaseBoneModelBuilder();

        virtual void BuildPoints();
        virtual void BuildEdges();
        virtual void BuildCenter();
        virtual std::shared_ptr<BoneModel> Get();
        virtual bool IsBuilt();
    protected:
        std::shared_ptr<BoneModelReader> _reader;
        std::shared_ptr<ModelStructure> _model;
        bool _isBuilt;
};
