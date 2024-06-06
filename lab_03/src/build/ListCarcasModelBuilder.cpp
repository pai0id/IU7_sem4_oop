#include "ListCarcasModelBuilder.hpp"
#include "../scene/LinkDotStructure.hpp"

ListCarcasModelBuilder::ListCarcasModelBuilder() {
    _model = std::make_shared<LinkDotStructure>();
}
