/**
 * Project Untitled
 */


#include "QTDrawerCreator.hpp"
#include "QTDrawer.hpp"

/**
 * SDLDrawerCreator implementation
 */

QTDrawerCreator::QTDrawerCreator(QGraphicsScene* scene) : _scene(scene) {}

std::shared_ptr<BaseDrawer> QTDrawerCreator::Create() {
    return std::make_shared<QTDrawer>(_scene);
}
