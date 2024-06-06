#ifndef _CAMERAPROJ_H
#define _CAMERAPROJ_H

#include "TransformAction.h"
#include "../scene/Camera.h"

class CameraProjectionAction : public TransformAction {
    public:
        CameraProjectionAction(std::shared_ptr<Camera> camera);
        CameraProjectionAction() = delete;

        ~CameraProjectionAction() = default;
    
    private:
        std::shared_ptr<Camera> _camera;
};

#endif
