/**
 * Project Untitled
 */


#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "BaseObject.hpp"

class Composite: public BaseObject {
private:
    VectorBaseObject _objects;

public:
    Composite() = default;
    Composite(PtrBaseObject first, ...);
    Composite(VectorBaseObject objects);

    ~Composite() = default;
    bool Add(std::initializer_list<PtrBaseObject> list) override;
    bool Remove(const iterator &it) override;
    bool IsComposite() const override;
    bool IsVisible() const override;
    Point GetCenter() const override;
    iterator begin();
    iterator end();

    void Accept(std::shared_ptr<Visitor> visitor) override;
};

#endif //_COMPOSITE_H
