#include "DrawSceneQtCommand.h"
#include "QtDrawerCreator.h"
#include <iostream>


DrawSceneQtCommand::DrawSceneQtCommand(QGraphicsScene* sceneQt)
{
    _sceneQt = sceneQt;
}


void DrawSceneQtCommand::Execute() {
    _drawManager->DrawScene<QtDrawerCreator, QGraphicsScene*>(_sceneManager, _sceneQt);  // done
}
