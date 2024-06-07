#pragma once
#include "BaseModel.h"
#include "ModelStructure.h"
#include "TransformAction.h"
#include <memory>
#include "DrawVisitor.h"
#include "TransformVisitor.h"


class Visitor;

class BoneModel : public BaseModel {
    friend class DrawVisitor;
    friend class TransformVisitor;
    public:
        BoneModel();
        explicit BoneModel(std::shared_ptr<ModelStructure>);
        explicit BoneModel(const BoneModel& other);
        ~BoneModel() = default;

        virtual void accept(std::shared_ptr<Visitor> v);
        virtual Point GetCenter() const;

    protected:
        std::shared_ptr<ModelStructure> _model;

};
