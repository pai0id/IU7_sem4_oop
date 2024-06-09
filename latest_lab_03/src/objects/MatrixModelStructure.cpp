#include "MatrixModelStructure.h"
#include "modelexception.h"
#include <iostream>

MatrixModelStructure::MatrixModelStructure() : _center(Point()), _points(std::vector<Point>()), _edgeMatrix(SquareMatrix<int>()) {};

void MatrixModelStructure::Transform(std::shared_ptr<TransformAction> action) {
    for (Point& point : _points) {
        action->TransformPoint(point);
    }
    action->TransformPoint(_center);
}

std::vector<Point> MatrixModelStructure::GetPoints() const {
    return _points;
}

std::vector<Edge> MatrixModelStructure::GetEdges() const {
    std::vector<Edge> _edges;

    for (size_t i = 0; i < _edgeMatrix.getSize(); ++i) {
        for (auto it = _edgeMatrix[i].begin() + i; it != _edgeMatrix[i].end(); ++it) {
            if (*it) {
                _edges.push_back(Edge(i, std::distance(_edgeMatrix[i].begin(), it)));
            }
        }
    }

    return _edges;
}

Point MatrixModelStructure::GetCenter() const {
    Point copy(_center);
    return copy;
}

void MatrixModelStructure::SetCenter(const Point& center) {
    _center = center;
}

void MatrixModelStructure::AddPoint(const Point& point) {
    _points.push_back(point);
    _edgeMatrix.Resize(_points.size(), false);
}

void MatrixModelStructure::AddEdge(const Edge& edge) {
    if (edge.GetFirst() >= _points.size() || edge.GetSecond() >= _points.size()) {
        time_t now = time(nullptr);
        throw EdgeOutOfPointsException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    *(_edgeMatrix[edge.GetFirst()].begin() + edge.GetSecond()) = true;
    *(_edgeMatrix[edge.GetSecond()].begin() + edge.GetFirst()) = true;
}

std::shared_ptr<ModelStructure> MatrixModelStructure::Clone() const {
    auto cloned = std::make_shared<MatrixModelStructure>();
    cloned->SetCenter(_center);
    for (const Point& point : _points) {
        cloned->AddPoint(point);
    }
    cloned->_edgeMatrix = _edgeMatrix;
    std::cout << "Cloned" << std::endl;

    return cloned;
}
