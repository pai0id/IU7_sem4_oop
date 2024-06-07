#include "TransformManager.h"
#include "RotateAction.h"
#include "ScaleAction.h"
#include "ShiftAction.h"
#include "TransformAction.h"
#include "TransformVisitor.h"
#include "Object.h"
#include <memory>

void TransformManager::RotateObject(std::shared_ptr<Object> object, double ox, double oy, double oz) {
    auto action = RotateAction(object->GetCenter(), ox, oy, oz);
    TransformVisitor vis(action);
    object->accept(std::make_shared<TransformVisitor>(vis));
}

void TransformManager::ScaleObject(std::shared_ptr<Object> object, double kx, double ky, double kz) {
    auto action = ScaleAction(object->GetCenter(), kx, ky, kz);
    TransformVisitor vis(action);
    object->accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::ShiftObject(std::shared_ptr<Object> object, double x, double y, double z) {
    auto action = ShiftAction(x, y, z);
    TransformVisitor vis(action);
    object->accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::TransformObject(std::shared_ptr<Object> object, const TransformAction& transform) {
    TransformVisitor vis(transform);
    object->accept(std::make_shared<TransformVisitor>(vis));
}
