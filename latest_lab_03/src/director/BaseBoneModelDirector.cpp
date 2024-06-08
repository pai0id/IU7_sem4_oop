#include "BaseBoneModelDirector.h"
#include "directorexception.h"
#include <iostream>


BaseBoneModelDirector::~BaseBoneModelDirector() {};

BaseBoneModelDirector::BaseBoneModelDirector(std::shared_ptr<BoneModelReader> reader)
: _reader(reader)  {}

void BaseBoneModelDirector::Create() {
    if (_reader == nullptr) {
        std::cout << "BaseBoneModelDirector::Create" << std::endl;
    }

    _builder->Build(_reader);
}

std::shared_ptr<Object> BaseBoneModelDirector::Get() {
    return _builder->Get();
}
