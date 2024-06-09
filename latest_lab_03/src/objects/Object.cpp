#include "Object.h"
#include "../visitor/Visitor.h"

std::size_t GetNextId() {
    static std::size_t id = 0;
    return ++id;
}

Object::Object() : _id(GetNextId()) {}

Object::~Object() {}


std::size_t Object::GetId() const {
    return _id;
}

void Object::Add(std::shared_ptr<Object> obj) { (void) obj;};

void Object::Remove(const iterator &it) { (void) it; };

Object::iterator Object::begin() { return iterator(); };

Object::iterator Object::end() { return iterator(); };

void Object::accept(std::shared_ptr<Visitor> v) { (void) v; };

std::shared_ptr<Object> Object::Clone() const { return nullptr;};

Point Object::GetCenter() const { return Point(); }

bool Object::IsComposite() const { return false; }
