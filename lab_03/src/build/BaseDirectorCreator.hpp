#ifndef _BASEDIRECTORCREATOR_H
#define _BASEDIRECTORCREATOR_H

#include "BaseDirector.hpp"
#include "BaseCarcasModelDirector.hpp"
#include "../loader/BaseLoader.hpp"


class BaseDirectorCreator {
    public:
        virtual ~BaseDirectorCreator() = default;
};


template <typename Director, typename... Args>
class BaseDirectorCreatorTemplate : public BaseDirectorCreator {
    public:
        virtual ~BaseDirectorCreatorTemplate() = default;

        virtual std::shared_ptr<Director> Create(Args&&... args) = 0;

};

using CarcasModelDirectorCreator_t = BaseDirectorCreatorTemplate<BaseCarcasModelDirector, std::shared_ptr<CarcasModelLoader>>;

#endif
