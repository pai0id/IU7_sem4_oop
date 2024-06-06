/**
 * Project Untitled
 */


#ifndef _TRANSFORMMANAGER_H
#define _TRANSFORMMANAGER_H

#include "../visitors/TransformVisitor.hpp"
#include "../scene/BaseObject.hpp"
#include "../scene/Scene.hpp"
#include <memory>

template <typename Type>
concept NotAbstract = !std::is_abstract_v<Type>;

template <typename Derived, typename Base>
concept Derivative = std::is_abstract_v<Base> && std::is_base_of_v<Base, Derived>;

template<typename Type, typename... Args>
concept Constructible = requires(Args... args)
{
    Type{args...};
};

class TransformManager {
    public:
        TransformManager() = default;
        ~TransformManager() = default;

        void RotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz);
        void ScaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz);
        void ShiftObject(std::shared_ptr<BaseObject> object, double x, double y, double z);
        void TransformObject(std::shared_ptr<BaseObject> object, const TransformAction& transform);
};

#endif //_TRANSFORMMANAGER_H
