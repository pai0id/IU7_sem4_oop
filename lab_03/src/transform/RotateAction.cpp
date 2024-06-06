#include "RotateAction.h"
#include "ShiftAction.h"
#include "multMat.h"
#include <vector>
#include <cmath>

RotateAction::RotateAction(double ox, double oy, double oz) {
    transf_mtr_t z = transf_mtr_t(4);
    (*z[0])[0] = cos(oz);
    (*z[0])[1] = sin(oz);
    (*z[1])[0] = -sin(oz);
    (*z[1])[1] = cos(oz);
    (*z[2])[2] = 1;
    (*z[3])[3] = 1;

    transf_mtr_t y = transf_mtr_t(4);
    (*y[0])[0] = cos(oy);
    (*y[0])[2] = -sin(oy);
    (*y[1])[1] = 1;
    (*y[2])[0] = sin(oy);
    (*y[2])[2] = cos(oy);
    (*y[3])[3] = 1;

    transf_mtr_t x = transf_mtr_t(4);
    (*x[0])[0] = 1;
    (*x[1])[1] = cos(ox);
    (*x[1])[2] = sin(ox);
    (*x[2])[1] = -sin(ox);
    (*x[2])[2] = cos(ox);
    (*x[3])[3] = 1;

    _matrix = multMat(_matrix, multMat(multMat(x, y), z));
}

RotateAction::RotateAction(const Point & center, double ox, double oy, double oz) {
    ShiftAction toCenter(Point(-center.GetX(), -center.GetY(), -center.GetZ()));
    _matrix = multMat(_matrix, toCenter.GetMatrix());
    RotateAction rotate(ox, oy, oz);
    _matrix = multMat(_matrix, rotate.GetMatrix());
    ShiftAction fromCenter(center);
    _matrix = multMat(_matrix, fromCenter.GetMatrix());
}
