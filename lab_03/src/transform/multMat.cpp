#include "multMat.h"

transf_mtr_t multMat(transf_mtr_t m1, transf_mtr_t m2) {
    size_t _size = m1.size();
    transf_mtr_t result = transf_mtr_t(_size);
    for (std::size_t i = 0; i < _size; i++) {
        for (std::size_t j = 0; j < _size; j++) {
            for (std::size_t k = 0; k < _size; k++) {
                (*result[i])[j] += (*m1[i])[k] * (*m2[k])[j];
            }
        }
    }
    return result;
}
