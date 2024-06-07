#include "RotateAction.hpp"
#include "ShiftAction.hpp"
#include "multMat.hpp"
#include <vector>
#include <cmath>

RotateAction::RotateAction(double ox, double oy, double oz) {
    transf_mtr_t z;
    fillZ(z);
    (*z[0])[0] = cos(oz);
    (*z[0])[1] = sin(oz);
    (*z[1])[0] = -sin(oz);
    (*z[1])[1] = cos(oz);
    (*z[2])[2] = 1;
    (*z[3])[3] = 1;

    transf_mtr_t y;
    fillZ(y);
    (*y[0])[0] = cos(oy);
    (*y[0])[2] = -sin(oy);
    (*y[1])[1] = 1;
    (*y[2])[0] = sin(oy);
    (*y[2])[2] = cos(oy);
    (*y[3])[3] = 1;

    transf_mtr_t x;
    fillZ(x);
    (*x[0])[0] = 1;
    (*x[1])[1] = cos(ox);
    (*x[1])[2] = sin(ox);
    (*x[2])[1] = -sin(ox);
    (*x[2])[2] = cos(ox);
    (*x[3])[3] = 1;

    auto xByY = multMat(x, y);
    auto xByYbyZ = multMat(xByY, z);
    _matrix = multMat(_matrix, xByYbyZ);
}

RotateAction::RotateAction(const Point & center, double ox, double oy, double oz) {
    ShiftAction toCenter(Point(-center.GetX(), -center.GetY(), -center.GetZ()));
    _matrix = multMat(_matrix, toCenter.GetMatrix());
    RotateAction rotate(ox, oy, oz);
    _matrix = multMat(_matrix, rotate.GetMatrix());
    ShiftAction fromCenter(center);
    _matrix = multMat(_matrix, fromCenter.GetMatrix());
}
