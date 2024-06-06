#ifndef _SHIFTACTION_H
#define _SHIFTACTION_H

#include "TransformAction.hpp"

class ShiftAction : public TransformAction {
    public:
        ShiftAction(double sx, double sy, double sz);
        ShiftAction(const Point &p);
        ShiftAction(double x, double y, double z, double w);
        ShiftAction();

        virtual ~ShiftAction() = default;
};

#endif
