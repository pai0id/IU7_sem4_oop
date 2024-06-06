#pragma once

#include "../managers/LoadManager.hpp"
#include "../managers/DrawManager.hpp"
#include "../managers/SceneManager.hpp"
#include "../managers/TransformManager.hpp"

class BaseCommand {
    public:
        BaseCommand() = default;
        virtual ~BaseCommand() = 0;

        void SetManagers(std::shared_ptr<SceneManager> sceneManager,
                         std::shared_ptr<LoadManager> loadManager,
                         std::shared_ptr<TransformManager> transformManager,
                         std::shared_ptr<DrawManager> drawManager);
                        

        virtual void Execute() = 0;
    
    protected:
        std::shared_ptr<SceneManager> _sceneManager;
        std::shared_ptr<LoadManager> _loadManager;
        std::shared_ptr<TransformManager> _transformManager;
        std::shared_ptr<DrawManager> _drawManager;
};
