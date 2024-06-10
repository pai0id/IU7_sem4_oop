#pragma once
#include "DrawManager.h"

template <typename DrawerCreator, typename... Args>
requires NotAbstract<DrawerCreator> && Derivative<DrawerCreator, BaseDrawerCreator> && Constructible<DrawerCreator, Args...>
void DrawManager::DrawScene(std::shared_ptr<SceneManager> sceneMngr, Args... args) {
    auto camera = sceneMngr->GetMainCamera();
    auto scene = sceneMngr->GetScene();
    DrawerCreator drawerCreator(args...);
    std::shared_ptr<BaseDrawer>drawer = drawerCreator.Create();
    DrawVisitor vis(drawer, camera);
    for (auto it = scene->begin(); it != scene->end(); ++it) {
        (*it)->accept(std::make_shared<DrawVisitor>(vis));
    }
}
