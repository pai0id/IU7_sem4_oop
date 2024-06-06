#include "MatrixCarcasModelBuilder.hpp"
#include "../scene/MatrixStructure.hpp"

MatrixCarcasModelBuilder::MatrixCarcasModelBuilder() {
    _model = std::make_shared<MatrixStructure>();
}
