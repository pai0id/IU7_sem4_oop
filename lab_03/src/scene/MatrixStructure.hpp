/**
 * Project Untitled
 */


#ifndef _MATRIXSTRUCTURE_H
#define _MATRIXSTRUCTURE_H

#include "CarcasModelStructure.hpp"

using mtr_t = std::vector<std::shared_ptr<std::vector<bool>>>;

class MatrixStructure: public CarcasModelStructure {
public:
    MatrixStructure();

    ~MatrixStructure() = default;
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
