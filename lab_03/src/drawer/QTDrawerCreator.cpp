/**
 * Project Untitled
 */


#include "QTDrawerCreator.h"
#include "QTDrawer.h"

/**
 * SDLDrawerCreator implementation
 */

QTDrawerCreator::QTDrawerCreator(QGraphicsScene* scene) : _scene(scene) {}

std::shared_ptr<BaseDrawer> QTDrawerCreator::Create() {
    return std::make_shared<QTDrawer>(_scene);
}
