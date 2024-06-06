/**
 * Project Untitled
 */


#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include "../scene/Scene.hpp"
#include "../scene/Camera.hpp"
#include "../scene/BaseObject.hpp"

class SceneManager {
protected:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Camera> _camera;
public:
    SceneManager();
    ~SceneManager() = default;
    void SetScene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> GetScene();

    void SetCamera(std::shared_ptr<Camera> camera);

    void AddObject(std::shared_ptr<BaseObject> object);
    std::vector<std::shared_ptr<BaseObject>> GetObjects();
    std::shared_ptr<Object> GetObject(std::size_t id);
    std::vector<std::size_t> GetObjectIds();
    void RemoveObject(std::size_t id);
    void MakeComposite(std::vector<size_t> ids);

    void AddCamera(const Point& pos);
    std::vector<std::shared_ptr<BaseObject>> GetCameras();
    std::vector<std::size_t> GetCameraIds();
    std::shared_ptr<Camera> GetCamera(std::size_t id);
    std::shared_ptr<Camera> GetMainCamera();
    void RemoveCamera(std::size_t id);
    void SetCamera(std::size_t id);

    void ClearScene();
};

#endif //_SCENEMANAGER_H
