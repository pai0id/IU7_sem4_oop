/**
 * Project Untitled
 */


#ifndef _DRAWVISITOR_H
#define _DRAWVISITOR_H

#include "Visitor.hpp"
#include "../drawer/BaseDrawer.hpp"

class DrawVisitor: public ObjectVisitor {
public:
    DrawVisitor() = delete;
    DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera);
    ~DrawVisitor() = default;

    virtual void visit(CarcasModel& model) override;
    virtual void visit(Camera& cam) override;

private:
    Point getCameraProjection(const Point& point) const;
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};

#endif //_DRAWVISITOR_H
