/**
 * Project Untitled
 */


#include "CarcasModel.hpp"

/**
 * CarcasModel implementation
 */

CarcasModel::CarcasModel() : _model(nullptr) {}
CarcasModel::CarcasModel(ModelStructurePtr model) : _model(model) {}
CarcasModel::CarcasModel(const CarcasModel& other) : _model(other._model) {}

//void CarcasModel::Accept(const Visitor& v)
//{
//   v.visit(*this);
//}

Point CarcasModel::GetCenter() const {
    return _model->GetCenter();
}
