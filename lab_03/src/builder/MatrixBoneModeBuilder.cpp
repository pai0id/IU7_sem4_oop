#include "MatrixBoneModelBuilder.h"
#include "MatrixModelStructure.h"

MatrixBoneModelBuilder::MatrixBoneModelBuilder(std::shared_ptr<BoneModelReader> reader) : BaseBoneModelBuilder(reader) {
    _model = std::make_shared<MatrixModelStructure>();
}
