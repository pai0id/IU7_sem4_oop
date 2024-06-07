/**
 * Project Untitled
 */


#include "TransformManager.hpp"
#include "../transform/RotateAction.hpp"
#include "../transform/ScaleAction.hpp"
#include "../transform/ShiftAction.hpp"
#include "../transform/TransformAction.hpp"
#include "../scene/BaseObject.hpp"
#include <memory>


void TransformManager::RotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz) {
    auto action = RotateAction(object->GetCenter(), ox, oy, oz);
    TransformVisitor vis(action);
    object->Accept(std::make_shared<TransformVisitor>(vis));
}

void TransformManager::ScaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz) {
    auto action = ScaleAction(object->GetCenter(), kx, ky, kz);
    TransformVisitor vis(action);
    object->Accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::ShiftObject(std::shared_ptr<BaseObject> object, double x, double y, double z) {
    auto action = ShiftAction(x, y, z);
    TransformVisitor vis(action);
    object->Accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::TransformObject(std::shared_ptr<BaseObject> object, const TransformAction& transform) {
    TransformVisitor vis(transform);
    object->Accept(std::make_shared<TransformVisitor>(vis));
}
