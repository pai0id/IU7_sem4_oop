#pragma once
#include "BaseBoneModelBuilder.h"

class ListBoneModelBuilder : public BaseBoneModelBuilder {
public:
    explicit ListBoneModelBuilder(std::shared_ptr<BoneModelReader> reader);
};
