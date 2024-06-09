#include "ListBoneModelBuilder.h"
#include "ListModelStructure.h"

ListBoneModelBuilder::ListBoneModelBuilder(std::shared_ptr<BoneModelReader> reader) : BaseBoneModelBuilder(reader) {
    _model = std::make_shared<ListModelStructure>();
}
