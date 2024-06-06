/**
 * Project Untitled
 */


#ifndef _SCALEVISITOR_H
#define _SCALEVISITOR_H

#include "Visitor.h"

class ScaleVisitor: public Visitor {
public:
    void visit(CarcasModel& model) override;
    void visit(Camera& cam) override;
};

#endif //_SCALEVISITOR_H
