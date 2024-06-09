#pragma once
#include "BaseBoneModelBuilder.h"


class MatrixBoneModelBuilder : public BaseBoneModelBuilder {
public:
    explicit MatrixBoneModelBuilder(std::shared_ptr<BoneModelReader> reader);
};
