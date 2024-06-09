#pragma once
#include <memory>

class BoneModel;
class Camera;

class Visitor {
    public:
        Visitor() {};

        virtual ~Visitor() {};
        virtual void visit(BoneModel& model) const = 0;
        virtual void visit(Camera& camera) const = 0;
};
