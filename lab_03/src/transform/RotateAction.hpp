#include "TransformAction.hpp"

class RotateAction : public TransformAction {
    public:
        RotateAction(double ox, double oy, double oz);
        RotateAction(const Point &center, double ox, double oy, double oz);
        
        virtual ~RotateAction() = default;
};
