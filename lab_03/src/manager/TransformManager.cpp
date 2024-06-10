#include "TransformManager.h"
#include "RotateAction.h"
#include "ScaleAction.h"
#include "ShiftAction.h"
#include "TransformAction.h"
#include "TransformVisitor.h"
#include "Object.h"
#include <memory>

void TransformManager::RotateObject(std::shared_ptr<Object> object, double ox, double oy, double oz) {
    TransformVisitor vis(std::make_shared<RotateAction>(object->GetCenter(), ox, oy, oz));
    object->accept(std::make_shared<TransformVisitor>(vis));
}

void TransformManager::ScaleObject(std::shared_ptr<Object> object, double kx, double ky, double kz) {
    TransformVisitor vis(std::make_shared<ScaleAction>(object->GetCenter(), kx, ky, kz));
    object->accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::ShiftObject(std::shared_ptr<Object> object, double x, double y, double z) {
    TransformVisitor vis(std::make_shared<ShiftAction>(x, y, z));
    object->accept(std::make_shared<TransformVisitor>(vis));
}
void TransformManager::TransformObject(std::shared_ptr<Object> object, std::shared_ptr<TransformAction> transform) {
    TransformVisitor vis(transform);
    object->accept(std::make_shared<TransformVisitor>(vis));
}
