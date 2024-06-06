#include "BaseCarcasModelBuilder.hpp"

BaseCarcasModelBuilder::~BaseCarcasModelBuilder() {}

void BaseCarcasModelBuilder::BuildPoint(const Point& p) {
    _model->AddPoint(p);
}

void BaseCarcasModelBuilder::BuildEdge(const Edge& edge) {
    _model->AddEdge(edge);
}

void BaseCarcasModelBuilder::BuildCenter(const Point& center) {
    _model->SetCenter(center);
}

std::shared_ptr<CarcasModel> BaseCarcasModelBuilder::Get() {
    return std::make_shared<CarcasModel>(_model);
}

bool BaseCarcasModelBuilder::IsBuilt() {
    return _model->GetPoints().size() != 0;
}
