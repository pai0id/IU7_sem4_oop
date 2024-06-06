/**
 * Project Untitled
 */


#include "TransformVisitor.hpp"

TransformVisitor::TransformVisitor(const TransformAction& action) : _action(action) {}

void TransformVisitor::visit(CarcasModel &model) {
    auto points = model._model->GetPoints();

    for (auto &p : points) {
        _action.TransformPoint(p);
    }
    Point p = model._model->GetCenter();
    _action.TransformPoint(p);
}

void TransformVisitor::visit(Camera& cam) {
    cam._self = _action.TransformPoint(cam._self);
    cam._normalForward = _action.TransformPoint(cam._normalForward);
    cam._normalUp = _action.TransformPoint(cam._normalUp);
    cam._normalRight = _action.TransformPoint(cam._normalRight);
}
