/**
 * Project Untitled
 */


#ifndef _MATRIXSTRUCTURE_H
#define _MATRIXSTRUCTURE_H

#include "ModelStructure.h"

using mtr_t = std::vector<std::vector<int>>;

class MatrixStructure: public ModelStructure {
public:
    MatrixStructure();

    ~MatrixStructure() = default;
    virtual void Transform(const TransformAction& action);
    virtual std::vector<Point> GetPoints() const;
    virtual std::vector<Edge> GetEdges() const;
    virtual void AddPoint(const Point& point);
    virtual void AddEdge(const Edge& edge);
    virtual Point GetCenter() const;
    virtual void SetCenter(const Point& center);
    virtual ModelStructurePtr Clone() const;

private:
    Point _center;

    std::vector<Point> _points;
    mtr_t _edgeMatrix;
};

#endif //_MATRIXSTRUCTURE_H
