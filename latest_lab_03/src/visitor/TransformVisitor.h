#pragma once

#include "Visitor.h"
#include "TransformAction.h"

class TransformVisitor : public Visitor {
public:
    TransformVisitor() = delete;
    TransformVisitor(const TransformAction& action);
    ~TransformVisitor() = default;

    virtual void visit(BoneModel& model) const;
    virtual void visit(Camera& camera) const ;
private:
    const TransformAction& _action;
};
