#include "MatrixCarcasModelDirector.hpp"
#include "MatrixCarcasModelBuilder.hpp"

MatrixCarcasModelDirector::MatrixCarcasModelDirector(std::shared_ptr<CarcasModelLoader> Loader)
: BaseCarcasModelDirector(Loader) {
    _builder = std::make_shared<MatrixCarcasModelBuilder>();
}
