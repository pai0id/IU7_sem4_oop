#ifndef _VISITOR_H
#define _VISITOR_H

class Camera;
class CarcasModel;

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit(CarcasModel& ref) const = 0;
    virtual void visit(Camera& ref) const = 0;
};

#endif
