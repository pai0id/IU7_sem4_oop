#include "BaseBoneModelDirector.h"
#include "directorexception.h"
#include <iostream>


BaseBoneModelDirector::~BaseBoneModelDirector() {};

BaseBoneModelDirector::BaseBoneModelDirector(std::shared_ptr<BoneModelReader> reader)
: _reader(reader)  {}

std::shared_ptr<Object> BaseBoneModelDirector::Create() {
    if (_reader == nullptr) {
        std::cout << "BaseBoneModelDirector::Create" << std::endl;
    }

    _builder->BuildPoints();
    _builder->BuildEdges();
    _builder->BuildCenter();
    return _builder->Get();
}
