#ifndef _FACADE_H
#define _FACADE_H

#include "command/BaseCommand.hpp"
#include "managers/LoadManager.hpp"
#include "managers/SceneManager.hpp"
#include "managers/TransformManager.hpp"
#include "managers/DrawManager.hpp"


class Facade {
    public :
        Facade();
        ~Facade() = default;

        void execute(BaseCommand &command);

    private :
        std::shared_ptr<SceneManager> _sceneManager;
        std::shared_ptr<LoadManager> _loadManager;
        std::shared_ptr<TransformManager> _transformManager;
        std::shared_ptr<DrawManager> _drawManager;
};

#endif //_FACADE_H
