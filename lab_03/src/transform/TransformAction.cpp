#include "TransformAction.hpp"
#include <vector>

TransformAction::TransformAction() {
    _matrix = transf_mtr_t(4);
    for (size_t i = 0; i < 4; ++i) {
        auto row = std::make_shared<std::vector<double>>(4, 0);
        _matrix[i] = row;
        (*_matrix[i])[i] = 1;
    }
}

Point &TransformAction::TransformPoint(Point &p) const {
    std::vector<double> pvector = {p.GetX(), p.GetY(), p.GetZ(), 1};
    std::vector<double> result(_matrix.size());
    for (std::size_t i = 0; i < _matrix.size(); i++) {
        for (std::size_t j = 0; j < _matrix.size(); j++) {
            result[i] += (*_matrix[j])[i] * pvector[j];
        }
    }
    if (result[3] == 0) {
        p.SetX(0);
        p.SetY(0);
        p.SetZ(0);
    } else {
        p.SetX(result[0] / result[3]);
        p.SetY(result[1] / result[3]);
        p.SetZ(result[2] / result[3]);
    }

    return p;
}

const transf_mtr_t &TransformAction::GetMatrix() const {
    return _matrix;
}

transf_mtr_t &TransformAction::GetMatrix() {
    return _matrix;
}
