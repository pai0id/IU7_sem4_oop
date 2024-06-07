#ifndef LOADERCREATOR_H
#define LOADERCREATOR_H

#include "BaseLoaderCreator.hpp"
#include "CarcasModelLoader.hpp"
#include "ModelTxtLoader.hpp"
#include "ModelSqLoader.hpp"
#include <memory>
#include "../concepts/concept.h"

template <typename LoaderBase, typename LoaderProd, typename... Args>
requires NotAbstract<LoaderProd> && Derivative<LoaderProd, LoaderBase> && Constructible<LoaderProd, Args...>
class LoaderCreator : public BaseLoaderCreatorTemplate<LoaderBase, Args...> {
    public:
        virtual ~LoaderCreator() = default;
        virtual std::shared_ptr<LoaderBase> Create(Args&&... args);
};

template <typename LoaderBase, typename LoaderProd, typename... Args>
requires NotAbstract<LoaderProd> && Derivative<LoaderProd, LoaderBase> && Constructible<LoaderProd, Args...>
std::shared_ptr<LoaderBase> LoaderCreator<LoaderBase, LoaderProd, Args...>::Create(Args&&... args) {
    return std::make_shared<LoaderProd>(args...);
}

using TxtCarcasModelLoaderCreator = LoaderCreator<CarcasModelLoader, ModelTxtLoader, const char *>;
using SqliteCarcasModelLoaderCreator = LoaderCreator<CarcasModelLoader, ModelSqliteLoader, const char *>;

#endif // LOADERCREATOR_H
