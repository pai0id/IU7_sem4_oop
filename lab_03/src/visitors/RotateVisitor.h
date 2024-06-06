/**
 * Project Untitled
 */


#ifndef _ROTATEVISITOR_H
#define _ROTATEVISITOR_H

#include "Visitor.h"

class RotateVisitor: public Visitor {
public:
    void visit(CarcasModel& model) override;
    void visit(Camera& cam) override;
};

#endif //_ROTATEVISITOR_H
