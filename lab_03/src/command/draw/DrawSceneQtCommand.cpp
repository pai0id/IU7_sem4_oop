#include "DrawSceneQtCommand.h"
#include "../../drawer/QTDrawerCreator.hpp"
#include <iostream>


DrawSceneQtCommand::DrawSceneQtCommand(QGraphicsScene* sceneQt)
{
    _sceneQt = sceneQt;
}


void DrawSceneQtCommand::Execute() {
    auto camera = _sceneManager->GetMainCamera();
    auto scene = _sceneManager->GetScene();
    _drawManager->DrawScene<QTDrawerCreator, QGraphicsScene*>(scene, camera, _sceneQt);
}
