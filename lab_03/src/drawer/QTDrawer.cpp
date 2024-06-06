/**
 * Project Untitled
 */


#include "QTDrawer.hpp"

/**
 * SDLDrawer implementation
 */

#include <iostream>

QTDrawer::QTDrawer(QGraphicsScene* scene) : _scene(scene) {}

void QTDrawer::DrawLine(const Point& p1, const Point& p2) {
    _scene->addLine(p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY());
}

void QTDrawer::Clear() {
    _scene->clear();
}
