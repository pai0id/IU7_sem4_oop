#ifndef _DIRECTORCREATOR_H
#define _DIRECTORCREATOR_H

#include <memory>
#include "BaseDirectorCreator.hpp"
#include "BaseCarcasModelDirector.hpp"
#include "ListCarcasModelDirector.hpp"
#include "MatrixCarcasModelDirector.hpp"
#include "concepts/concept.h"

template <typename DirectorBase, typename DirectorProd, typename... Args>
requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
class DirectorCreator : public BaseDirectorCreatorTemplate<DirectorBase, Args...> {
    public:
        virtual ~DirectorCreator() = default;
        virtual std::shared_ptr<DirectorBase> Create(Args&&... args);
};

using ListCarcasModelDirectorCreator = DirectorCreator<BaseCarcasModelDirector, ListCarcasModelDirector, std::shared_ptr<CarcasModelLoader>>;
using MatrixCarcasModelDirectorCreator = DirectorCreator<BaseCarcasModelDirector, MatrixCarcasModelDirector, std::shared_ptr<CarcasModelLoader>>;

template <typename DirectorBase, typename DirectorProd, typename... Args>
requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
std::shared_ptr<DirectorBase> DirectorCreator<DirectorBase, DirectorProd, Args...>::Create(Args&&... args) {
    return std::make_shared<DirectorProd>(args...);
}

#endif
