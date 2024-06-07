/**
 * Project Untitled
 */


#include "DrawVisitor.hpp"
#include "../transform/CameraProjectionAction.hpp"
#include "../scene/Camera.hpp"
#include "../scene/CarcasModel.hpp"

/**
 * DrawVisitor implementation
 */

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera) : _drawer(drawer), _camera(camera) {}

Point DrawVisitor::getCameraProjection(const Point& point) const {
    CameraProjectionAction action(_camera);
    Point copy(point);
    action.TransformPoint(copy);
    return copy;
}

#define FOCUS 500.0
#define R (1 / FOCUS)

void DrawVisitor::visit(CarcasModel &model) const {
    auto points = model._model->GetPoints();
    auto edges = model._model->GetEdges();

    for (auto &edge : edges) {
        Point &p1 = points[edge.GetFirst()];
        Point &p2 = points[edge.GetSecond()];
        Point proj1(getCameraProjection(p1));
        Point proj2(getCameraProjection(p2));

        proj1.SetX(proj1.GetX() * (1 / (R * proj1.GetZ())));
        proj1.SetY(proj1.GetY() * (1 / (R * proj1.GetZ())));

        proj2.SetX(proj2.GetX() * (1 / (R * proj2.GetZ())));
        proj2.SetY(proj2.GetY() * (1 / (R * proj2.GetZ())));

        if (proj1.GetZ() > 0 && proj2.GetZ() > 0) {
            _drawer->DrawLine(proj1, proj2);
        }

    }
}
void DrawVisitor::visit(Camera& camera) const {
    (void) camera;
}
