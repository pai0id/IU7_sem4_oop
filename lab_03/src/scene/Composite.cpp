/**
 * Project Untitled
 */


#include "Composite.h"
#include "CenterStrategy.h"

/**
 * Composite implementation
 */

Composite::Composite(PtrBaseObject first, ...)
{
    for (PtrBaseObject* ptr = &first; *ptr; ++ptr)
        _objects.push_back(*ptr);
}

Composite::Composite(VectorBaseObject objects) : _objects(objects) {}

void Composite::Add(std::shared_ptr<BaseObject> obj) {
    _objects.push_back(obj);
}

void Composite::Remove(const iterator &it) {
    _objects.erase(it);
}

void Composite::Accept(const Visitor &v) {
    v.Visit(*this);
}

Composite::iterator Composite::begin() {
    return _objects.begin();
}

Composite::iterator Composite::end() {
    return _objects.end();
}

bool Composite::IsComposite() const { return true; }

bool Composite::IsVisible() const { return true; }

Point Composite::GetCenter() const {
    std::vector<Point> centers;
    for (auto &obj : _objects) {
        centers.push_back(obj->GetCenter());
    }
    ClassicCenterStrategy centerStrategy;
    return centerStrategy.CenterAlgorithm(centers);
}
