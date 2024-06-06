/**
 * Project Untitled
 */


#ifndef _SCENE_H
#define _SCENE_H

#include "BaseObject.h"
#include "../visitors/Visitor.h"
#include "../managers/SceneManager.h"
#include <list>

class Scene {
    friend class SceneManager;
public:
    using iterator=std::list<std::shared_ptr<BaseObject>>::iterator;
    using const_iterator=std::list<std::shared_ptr<BaseObject>>::const_iterator;
    using reverse_iterator=std::list<std::shared_ptr<BaseObject>>::reverse_iterator;
    using const_reverse_iterator=std::list<std::shared_ptr<BaseObject>>::const_reverse_iterator;
    using size_type=std::list<std::shared_ptr<BaseObject>>::size_type;
    using difference_type=std::list<std::shared_ptr<BaseObject>>::difference_type;
    using iteratorCamera=std::list<iterator>::const_iterator;

    Scene();
    ~Scene() = default;

    void AddBaseObject(const std::shared_ptr<BaseObject> obj);
    void RemoveBaseObject(const const_iterator& it);
    void AddComposite(const std::vector<std::shared_ptr<BaseObject>> BaseObjects);

    void AddCamera(const std::shared_ptr<BaseObject> obj);
    void RemoveCamera(const std::list<iterator>::const_iterator &it);
    std::shared_ptr<BaseObject> GetCamera(const iteratorCamera &it);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
    size_type size() const;

    iteratorCamera beginCamera();
    iteratorCamera endCamera();

    std::shared_ptr<Scene> Clone();

protected:
    std::list<std::shared_ptr<BaseObject>> _BaseObjects;
    std::list<iterator> _cameras;
};

#endif //_SCENE_H
