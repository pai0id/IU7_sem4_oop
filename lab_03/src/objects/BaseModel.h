#pragma once
#include "VisibleObject.h"


class BaseModel : public VisibleObject {
    public:
        BaseModel();
        virtual ~BaseModel() = 0;

        virtual void Add(std::shared_ptr<Object> obj);
        virtual void Remove(const iterator &it);
        virtual iterator begin();
        virtual iterator end();
        virtual void accept(std::shared_ptr<Visitor> v);
        virtual std::shared_ptr<Object> Clone() const;
};
