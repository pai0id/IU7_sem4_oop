#include "ScaleAction.hpp"
#include "ShiftAction.hpp"
#include "multMat.hpp"

ScaleAction::ScaleAction(double mx, double my, double mz) {
    (*_matrix[0])[0] = mx;
    (*_matrix[1])[1] = my;
    (*_matrix[2])[2] = mz;
}

ScaleAction::ScaleAction(double m) {
    (*_matrix[0])[0] = m;
    (*_matrix[1])[1] = m;
    (*_matrix[2])[2] = m;
} 

ScaleAction::ScaleAction(const Point& center, double mx, double my, double mz) {
    ShiftAction toCenter(Point(-center.GetX(), -center.GetY(), -center.GetZ()));
    _matrix = multMat(_matrix, toCenter.GetMatrix());
    ScaleAction scale(mx, my, mz);
    _matrix = multMat(_matrix, scale.GetMatrix());
    ShiftAction fromCenter(center);
    _matrix = multMat(_matrix, fromCenter.GetMatrix());
}

ScaleAction::ScaleAction(const Point& center, double m) {
    ShiftAction toCenter(Point(-center.GetX(), -center.GetY(), -center.GetZ()));
    _matrix = multMat(_matrix, toCenter.GetMatrix());
    ScaleAction scale(m);
    _matrix = multMat(_matrix, scale.GetMatrix());
    ShiftAction fromCenter(center);
    _matrix = multMat(_matrix, fromCenter.GetMatrix());
}
