/**
 * Project Untitled
 */


#ifndef _LINKDOTSTRUCTURE_H
#define _LINKDOTSTRUCTURE_H

#include "ModelStructure.h"


class LinkDotStructure: public ModelStructure {
public:
    LinkDotStructure();

    ~LinkDotStructure() = default;
    virtual void Transform(const TransformAction& action);
    virtual std::vector<Point> GetPoints() const;
    virtual std::vector<Edge> GetEdges() const;
    virtual void AddPoint(const Point& point);
    virtual void AddEdge(const Edge& edge);
    virtual Point GetCenter() const;
    virtual void SetCenter(const Point& center);
    virtual ModelStructurePtr Clone() const;

protected:
    Point _center;

    std::vector<Point> _points;
    std::vector<Edge> _edges;
};

#endif //_LINKDOTSTRUCTURE_H
