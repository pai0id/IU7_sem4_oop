#include "BaseBoneModelBuilder.h"


BaseBoneModelBuilder::~BaseBoneModelBuilder() {}

void BaseBoneModelBuilder::Build(std::shared_ptr<BoneModelReader> _reader) {
    _reader->Open();
    auto points = _reader->ReadPoints();
    auto edges = _reader->ReadEdges();
    _reader->Close();

    for (auto &p : points) {
        _model->AddPoint(p);
    }
    for (auto &e : edges) {
        _model->AddEdge(e);
    }

    _model->SetCenter(_reader->ReadCenter());
}

std::shared_ptr<BoneModel> BaseBoneModelBuilder::Get() {
    return std::make_shared<BoneModel>(_model);
}

bool BaseBoneModelBuilder::IsBuilt() {
    return _model->GetPoints().size() != 0;
}
