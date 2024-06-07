/**
 * Project Untitled
 */


#ifndef _DRAWVISITOR_H
#define _DRAWVISITOR_H

#include "../drawer/BaseDrawer.hpp"
#include "Visitor.hpp"
#include <memory>

class Camera;
class CarcasModel;

class DrawVisitor: public Visitor {
public:
    DrawVisitor() = delete;
    DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera);
    ~DrawVisitor() = default;

    virtual void visit(CarcasModel& model) const;
    virtual void visit(Camera& cam) const;

private:
    Point getCameraProjection(const Point& point) const;
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;
};

#endif //_DRAWVISITOR_H
