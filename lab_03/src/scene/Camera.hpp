/**
 * Project Untitled
 */


#ifndef _CAMERA_H
#define _CAMERA_H

#include "../visitors/TransformVisitor.hpp"
#include "InvisibleObject.hpp"

class Camera : public InvisibleObject {
    friend class DrawVisitor;
    friend class TransformVisitor;
    friend class CameraProjectionAction;
public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Point &p);
    explicit Camera(const Camera &other);

    bool IsComposite() const;
    virtual void Accept(std::shared_ptr<Visitor> v);
    Point GetCenter() const;

    virtual ~Camera() = default;

protected:
    Point _self;
    Point _normalForward;
    Point _normalUp;
    Point _normalRight;
};

#endif //_CAMERA_H
