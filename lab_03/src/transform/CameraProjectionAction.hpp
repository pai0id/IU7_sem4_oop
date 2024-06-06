#ifndef _CAMERAPROJ_H
#define _CAMERAPROJ_H

#include "TransformAction.hpp"
#include "../scene/Camera.hpp"

class CameraProjectionAction : public TransformAction {
    public:
        CameraProjectionAction(std::shared_ptr<Camera> camera);
        CameraProjectionAction() = delete;

        ~CameraProjectionAction() = default;
    
    private:
        std::shared_ptr<Camera> _camera;
};

#endif
