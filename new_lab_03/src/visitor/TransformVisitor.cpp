#include "TransformVisitor.h"
#include "Camera.h"
#include "BoneModel.h"

TransformVisitor::TransformVisitor(const TransformAction& action) : _action(action) {}

void TransformVisitor::visit(BoneModel &model) const {
    model._model->Transform(_action);
}

void TransformVisitor::visit(Camera& cam) const {
    cam._self = _action.TransformPoint(cam._self);
    cam._normalForward = _action.TransformPoint(cam._normalForward);
    cam._normalUp = _action.TransformPoint(cam._normalUp);
    cam._normalRight = _action.TransformPoint(cam._normalRight);
}
