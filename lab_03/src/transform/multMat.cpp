#include "multMat.hpp"

transf_mtr_t multMat(transf_mtr_t &m1, transf_mtr_t &m2) {
    transf_mtr_t result;
    fillZ(result);
    for (std::size_t i = 0; i < 4; i++) {
        for (std::size_t j = 0; j < 4; j++) {
            for (std::size_t k = 0; k < 4; k++) {
                (*result[i])[j] += (*m1[i])[k] * (*m2[k])[j];
            }
        }
    }
    return result;
}

void fillZ(transf_mtr_t &m) {
    for (size_t i = 0; i < 4; ++i) {
        auto row = std::make_shared<std::vector<double>>(4, 0.0);
        m.push_back(row);
    }
}
