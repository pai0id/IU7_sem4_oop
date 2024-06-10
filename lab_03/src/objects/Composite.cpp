#include "Composite.h"
#include "Visitor.h"
#include "FindCenter.h"

Composite::Composite(std::vector<std::shared_ptr<Object>> vec) : _objects(vec) {}

void Composite::Add(std::shared_ptr<Object> obj) {
    _objects.push_back(obj);
}

void Composite::Remove(const iterator &it) {
    _objects.erase(it);
}

std::shared_ptr<Object> Composite::Clone() const {
    std::shared_ptr<Composite> copy = std::make_shared<Composite>();
    for (auto &obj : _objects) {
        copy->Add(obj->Clone());
    }
    return copy;
}

void Composite::accept(std::shared_ptr<Visitor> v) {
    for (auto& elem : _objects)
        elem->accept(v);
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
    return FindCenter(centers);
}
