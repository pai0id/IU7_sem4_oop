#include "ListCarcasModelDirector.hpp"
#include "ListCarcasModelBuilder.hpp"

ListCarcasModelDirector::ListCarcasModelDirector(std::shared_ptr<CarcasModelLoader> Loader)
: BaseCarcasModelDirector(Loader) {
    _builder = std::make_shared<ListCarcasModelBuilder>();
}
