/**
 * Project Untitled
 */


#ifndef _BASELOADERCREATOR_H
#define _BASELOADERCREATOR_H

#include <memory>
#include <concepts>
#include "BoneModelLoader.h"

class BaseLoaderCreator {
    public:
        virtual ~BaseLoaderCreator() = default;
};

template <typename Loader, typename... Args>
class BaseLoaderCreatorTemplate : public BaseLoaderCreator {
    public:
        virtual ~BaseLoaderCreatorTemplate() = default;

        virtual std::shared_ptr<Loader> Create(Args&&... args) = 0;

};

using BoneModelLoaderCreator_t = BaseLoaderCreatorTemplate<BoneModelLoader, const char*>;

#endif //_BASELOADERCREATOR_H
