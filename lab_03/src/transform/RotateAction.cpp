#include "RotateAction.hpp"
#include "ShiftAction.hpp"
#include "multMat.hpp"
#include <vector>
#include <math.hpp>

RotateAction::RotateAction(double ox, double oy, double oz) {
    long double _ox, _oy, _oz;
    _ox = (long double)ox;
    _oy = (long double)oy;
    _oz = (long double)oz;
    transf_mtr_t z = transf_mtr_t(4);
    (*z[0])[0] = cos(_oz);
    (*z[0])[1] = sin(_oz);
    (*z[1])[0] = -sin(_oz);
    (*z[1])[1] = cos(_oz);
    (*z[2])[2] = 1;
    (*z[3])[3] = 1;

    transf_mtr_t y = transf_mtr_t(4);
    (*y[0])[0] = cos(_oy);
    (*y[0])[2] = -sin(_oy);
    (*y[1])[1] = 1;
    (*y[2])[0] = sin(_oy);
    (*y[2])[2] = cos(_oy);
    (*y[3])[3] = 1;

    transf_mtr_t x = transf_mtr_t(4);
    (*x[0])[0] = 1;
    (*x[1])[1] = cos(_ox);
    (*x[1])[2] = sin(_ox);
    (*x[2])[1] = -sin(_ox);
    (*x[2])[2] = cos(_ox);
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
