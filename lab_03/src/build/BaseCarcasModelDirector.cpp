#include "BaseCarcasModelDirector.hpp"
#include "../exception/directorexception.hpp"
#include <iostream>

BaseCarcasModelDirector::~BaseCarcasModelDirector() {};

BaseCarcasModelDirector::BaseCarcasModelDirector(std::shared_ptr<CarcasModelLoader> Loader)
: _strategy(std::make_shared<ClassicCenterStrategy>()), _Loader(Loader)  {}

void BaseCarcasModelDirector::Create() {
    if (_Loader == nullptr) {
        std::cout << "BaseCarcasModelDirector::Create" << std::endl;
    }
    _Loader->Open();
    auto points = _Loader->ReadPoints();
    auto edges = _Loader->ReadEdges();
    _Loader->Close();

    for (auto &p : points) {
        _builder->BuildPoint(p);
    }
    for (auto &e : edges) {
        _builder->BuildEdge(e);
    }

    _builder->BuildCenter(_strategy->CenterAlgorithm(points));
}

std::shared_ptr<BaseObject> BaseCarcasModelDirector::Get() {
    return _builder->Get();
}
