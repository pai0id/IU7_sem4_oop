/**
 * Project Untitled
 */


#include "LinkDotStructure.h"

/**
 * LinkDotStructure implementation
 */

LinkDotStructure::LinkDotStructure() : _center(Point()), _points(std::vector<Point>()), _edges(std::vector<Edge>()) {};

void LinkDotStructure::Transform(const TransformAction& action) {
    for (Point& point : _points) {
        action.TransformPoint(point);
    }
    action.TransformPoint(_center);
}

std::vector<Point> LinkDotStructure::GetPoints() const {
    return _points;
}

std::vector<Edge> LinkDotStructure::GetEdges() const {
    return _edges;
}

Point LinkDotStructure::GetCenter() const {
    Point copy(_center);
    return copy;
}

void LinkDotStructure::SetCenter(const Point& center) {
    _center = center;
}

void LinkDotStructure::AddPoint(const Point& point) {
    _points.push_back(point);
}

void LinkDotStructure::AddEdge(const Edge& edge) {
    _edges.push_back(edge);
}

std::shared_ptr<ModelStructure> LinkDotStructure::Clone() const {
    auto cloned = std::make_shared<LinkDotStructure>();
    cloned->SetCenter(_center);
    for (const Point& point : _points) {
        cloned->AddPoint(point);
    }

    for (const Edge& edge : _edges) {
        cloned->AddEdge(edge);
    }

    return cloned;
}
