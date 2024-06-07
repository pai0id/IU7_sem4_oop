/**
 * Project Untitled
 */


#ifndef _TRANSFORMVISITOR_H
#define _TRANSFORMVISITOR_H

#include "../transform/TransformAction.hpp"
#include "Visitor.hpp"

class Camera;
class CarcasModel;

class TransformVisitor : public Visitor {
public:
    TransformVisitor() = delete;
    TransformVisitor(const TransformAction& action);
    ~TransformVisitor() = default;

    virtual void visit(CarcasModel& model) const;
    virtual void visit(Camera& cam) const;
private:
    const TransformAction& _action;
};

#endif
