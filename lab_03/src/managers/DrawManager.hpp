/**
 * Project Untitled
 */


#ifndef _DRAWMANAGER_H
#define _DRAWMANAGER_H

#include "../visitors/DrawVisitor.hpp"
#include "../scene/Scene.hpp"
#include "../drawer/BaseDrawerCreator.hpp"
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

class DrawManager {
    public:
        DrawManager() = default;
        ~DrawManager() = default;

        template <typename DrawerCreator, typename... Args>
        requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
        void DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args);
};

template <typename DrawerCreator, typename... Args>
requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
void DrawManager::DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera, Args... args) {
    DrawerCreator drawerCreator(args...);
    std::shared_ptr<BaseDrawer>drawer = drawerCreator.Create();
    DrawVisitor vis(drawer, camera);
    for (auto it = scene->begin(); it != scene->end(); ++it) {
        (*it)->Accept(vis);
    }
}

#endif //_DRAWMANAGER_H
