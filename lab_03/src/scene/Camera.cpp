/**
 * Project Untitled
 */


#include "Camera.hpp"

/**
 * Camera implementation
 */


Camera::Camera() : _self(Point()), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(const Point &self) : _self(self), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(const Camera &other) : _self(other._self), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

Camera::Camera(double x, double y, double z) : _self(Point(x, y, z)), _normalForward(Point(0, 0, 1)), _normalUp(Point(0, 1, 0)), _normalRight(Point(1, 0, 0)) {}

//void Camera::Accept(std::shared_ptr<ObjectVisitor> v) {
//    v->visit(*this);
//}

bool Camera::IsComposite() const { return false; }

Point Camera::GetCenter() const {
    Point copy(_self);
    return copy;
}
