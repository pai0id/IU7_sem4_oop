/**
 * Project Untitled
 */


#ifndef _CAMERA_H
#define _CAMERA_H

#include "InvisibleObject.h"
#include "../visitors/DrawVisitor.h"
#include "../visitors/MoveVisitor.h"
#include "../visitors/RotateVisitor.h"

class Camera: public InvisibleObject, public VisitableObject<Camera> {
    using VisitableObject<Camera>::VisitableObject;
    friend class DrawVisitor;
    friend class RotateVisitor;
    friend class MoveVisitor;
    friend class Draw
    friend class CameraProjectionAction;
public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Point &p);
    explicit Camera(const Camera &other);

    virtual bool IsComposite() const;
//    virtual void Accept(std::shared_ptr<ObjectVisitor> v);
    virtual Point GetCenter() const;

    virtual ~Camera() = default;

protected:
    Point _self;
    Point _normalForward;
    Point _normalUp;
    Point _normalRight;
};

#endif //_CAMERA_H
