#include "BaseBoneModelBuilder.h"

BaseBoneModelBuilder::BaseBoneModelBuilder() : _reader(nullptr), _isBuilt(false) {}

BaseBoneModelBuilder::BaseBoneModelBuilder(std::shared_ptr<BoneModelReader> reader) : _reader(reader), _isBuilt(false) {
    _reader->Open();
}

BaseBoneModelBuilder::~BaseBoneModelBuilder() {
    if (_reader && _reader->IsOpen()) {
        _reader->Close();
    }
}

void BaseBoneModelBuilder::BuildPoints() {
    if (_reader) {
        auto points = _reader->ReadPoints();

        for (auto &p : points) {
            _model->AddPoint(p);
        }
    }
}

void BaseBoneModelBuilder::BuildEdges() {
    if (_reader) {
        auto edges = _reader->ReadEdges();

        for (auto &e : edges) {
            _model->AddEdge(e);
        }
    }
}

void BaseBoneModelBuilder::BuildCenter() {
    if (_reader) {
        _model->SetCenter(_reader->ReadCenter());
    }
}

std::shared_ptr<BoneModel> BaseBoneModelBuilder::Get() {
    return std::make_shared<BoneModel>(_model);
}

bool BaseBoneModelBuilder::IsBuilt() {
    return _isBuilt;
}
