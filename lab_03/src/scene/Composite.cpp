/**
 * Project Untitled
 */


#include "Composite.hpp"
#include "CenterStrategy.hpp"

/**
 * Composite implementation
 */

Composite::Composite(PtrBaseObject first, ...)
{
    for (PtrBaseObject* ptr = &first; *ptr; ++ptr)
        _objects.push_back(*ptr);
}

Composite::Composite(VectorBaseObject objects) : _objects(objects) {}

bool Composite::Add(std::initializer_list<PtrBaseObject> list) {
    for (auto elem : list)
        _objects.push_back(elem);

    return true;
}

bool Composite::Remove(const iterator &it) {
    _objects.erase(it);
    return true;
}

void Composite::Accept(std::shared_ptr<Visitor> visitor) {
    for (auto& elem : _objects)
        elem->Accept(visitor);
}

Composite::iterator Composite::begin() {
    return _objects.begin();
}

Composite::iterator Composite::end() {
    return _objects.end();
}

bool Composite::IsComposite() const { return true; }

bool Composite::IsVisible() const {
    for (auto elem : _objects)
        if (elem->IsVisible())
            return true;
    return false;
}

Point Composite::GetCenter() const {
    std::vector<Point> centers;
    for (auto &obj : _objects) {
        centers.push_back(obj->GetCenter());
    }
    ClassicCenterStrategy centerStrategy;
    return centerStrategy.CenterAlgorithm(centers);
}
