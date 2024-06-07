#pragma once
#include "TransformAction.h"
#include <memory>
#include <vector>
#include <cstddef>

class Visitor;

std::size_t GetNextId();

class Object {
    public:
        using iterator = std::vector<std::shared_ptr<Object>>::iterator;
        Object();
        virtual ~Object() = 0;

        virtual void Add(std::shared_ptr<Object> obj);
        virtual void Remove(const iterator &it);
        virtual iterator begin();
        virtual iterator end();
        virtual void accept(std::shared_ptr<Visitor> v);
        virtual std::shared_ptr<Object> Clone() const;
        
        virtual std::size_t GetId() const;

        virtual Point GetCenter() const = 0;
        virtual bool IsVisible() const = 0;
        virtual bool IsComposite() const = 0;
    
    protected:
        std::size_t _id = 0;


};
