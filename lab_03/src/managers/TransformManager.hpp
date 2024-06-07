/**
 * Project Untitled
 */


#ifndef _TRANSFORMMANAGER_H
#define _TRANSFORMMANAGER_H

#include "../visitors/TransformVisitor.hpp"
#include "../scene/BaseObject.hpp"
#include "../scene/Scene.hpp"
#include <memory>
#include "concepts/concept.h"

class TransformManager {
    public:
        TransformManager() = default;
        ~TransformManager() = default;

        void RotateObject(std::shared_ptr<BaseObject> object, double ox, double oy, double oz);
        void ScaleObject(std::shared_ptr<BaseObject> object, double kx, double ky, double kz);
        void ShiftObject(std::shared_ptr<BaseObject> object, double x, double y, double z);
        void TransformObject(std::shared_ptr<BaseObject> object, const TransformAction& transform);
};

#endif //_TRANSFORMMANAGER_H
