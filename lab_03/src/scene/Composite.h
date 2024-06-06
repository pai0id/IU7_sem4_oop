/**
 * Project Untitled
 */


#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "BaseObject.h"

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
    bool IsComposite() const;
    bool IsVisible() const;
    Point GetCenter() const;
    iterator begin();
    iterator end();

    void Accept(std::shared_ptr<ObjectVisitor> visitor) override;
};

#endif //_COMPOSITE_H
