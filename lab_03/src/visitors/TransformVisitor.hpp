/**
 * Project Untitled
 */


#ifndef _TRANSFORMVISITOR_H
#define _TRANSFORMVISITOR_H

#include "Visitor.hpp"
#include "../transform/TransformAction.hpp"

class TransformVisitor: public ObjectVisitor {
public:
    TransformVisitor() = delete;
    TransformVisitor(const TransformAction& action);
    ~TransformVisitor() = default;

    void visit(CarcasModel& model) override;
    void visit(Camera& cam) override;
private:
    const TransformAction& _action;
};

#endif
