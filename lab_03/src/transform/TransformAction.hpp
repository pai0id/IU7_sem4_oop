#ifndef _TRANSFORMACTION_H
#define _TRANSFORMACTION_H

#include "../scene/Point.hpp"
#include <memory>
#include <vector>
#include <cstddef>

using transf_mtr_t = std::vector<std::shared_ptr<std::vector<double>>>;

class TransformAction {
    public:
    TransformAction();

    virtual ~TransformAction() = default;

    Point &TransformPoint(Point &p) const;
    const transf_mtr_t &GetMatrix() const;
    transf_mtr_t &GetMatrix();

    protected:
        transf_mtr_t _matrix;
};

#endif
