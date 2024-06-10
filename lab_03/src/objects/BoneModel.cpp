#include "BoneModel.h"
#include "../visitor/Visitor.h"


BoneModel::BoneModel() : _model(nullptr) {}

BoneModel::BoneModel(std::shared_ptr<ModelStructure> model) : _model(model) {}

BoneModel::BoneModel(const BoneModel &model) : _model(model._model) {}

void BoneModel::accept(std::shared_ptr<Visitor> v) {
    v->visit(*this);
}

Point BoneModel::GetCenter() const {
    return _model->GetCenter();
}
