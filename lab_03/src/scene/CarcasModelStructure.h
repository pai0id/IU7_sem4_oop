/**
 * Project Untitled
 */


#ifndef _MODELSTRUCTURE_H
#define _MODELSTRUCTURE_H

#include <vector>
#include <memory>
#include "Point.h"
#include "Edge.h"

class CarcasModelStructure;

using ModelStructurePtr = std::shared_ptr<CarcasModelStructure>;

class CarcasModelStructure {
public:
    CarcasModelStructure() = default;
    CarcasModelStructure(const CarcasModelStructure& other) = delete;
    CarcasModelStructure(CarcasModelStructure&& other) = delete;
    virtual ~CarcasModelStructure() = 0;

    virtual std::vector<Point> GetPoints() const = 0;
    virtual std::vector<Edge> GetEdges() const = 0;
    virtual void AddPoint(const Point& point) = 0;
    virtual void AddEdge(const Edge& edge) = 0;
    virtual Point GetCenter() const = 0;
    virtual void SetCenter(const Point& center) = 0;
    virtual ModelStructurePtr Clone() const = 0;
};

#endif //_MODELSTRUCTURE_H
