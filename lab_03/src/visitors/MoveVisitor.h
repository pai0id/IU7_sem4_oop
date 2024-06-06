/**
 * Project Untitled
 */


#ifndef _MOVEVISITOR_H
#define _MOVEVISITOR_H

#include "Visitor.h"

class MoveVisitor: public Visitor {
public:
    void visit(CarcasModel& model) override;
    void visit(Camera& cam) override;
};

#endif //_MOVEVISITOR_H
