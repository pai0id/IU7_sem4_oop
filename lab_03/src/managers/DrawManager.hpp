/**
 * Project Untitled
 */


#ifndef _DRAWMANAGER_H
#define _DRAWMANAGER_H

#include <memory>
#include "../visitors/DrawVisitor.hpp"
#include "../scene/Scene.hpp"
#include "../drawer/BaseDrawerCreator.hpp"
#include "concepts/concept.h"

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
        (*it)->Accept(std::make_shared<DrawVisitor>(vis));
    }
}

#endif //_DRAWMANAGER_H
