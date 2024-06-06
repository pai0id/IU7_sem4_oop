/**
 * Project Untitled
 */


#include "MatrixStructure.h"
#include <iostream>
#include <memory>
#include <ctime>

/**
 * MatrixStructure implementation
 */

MatrixStructure::MatrixStructure() : _center(Point()), _points(std::vector<Point>()), _edgeMatrix(mtr_t()) {};

std::vector<Point> MatrixStructure::GetPoints() const {
    return _points;
}

std::vector<Edge> MatrixStructure::GetEdges() const {
    std::vector<Edge> _edges;

    for (size_t i = 0; i < _edgeMatrix.size(); ++i) {
        for (auto it = _edgeMatrix[i]->cbegin() + i; it != _edgeMatrix[i]->cend(); ++it) {
            if (*it) {
                _edges.push_back(Edge(i, std::distance(_edgeMatrix[i]->cbegin(), it)));
            }
        }
    }

    return _edges;
}

Point MatrixStructure::GetCenter() const {
    Point copy(_center);
    return copy;
}

void MatrixStructure::SetCenter(const Point& center) {
    _center = center;
}

void MatrixStructure::AddPoint(const Point& point) {
    _points.push_back(point);
    size_t size = _edgeMatrix.size();
    if (_points.size() < size) {
        for (std::size_t i = _points.size(); i < size; i++) {
            _edgeMatrix.pop_back();
        }
        for (std::size_t i = 0; i < _points.size(); i++) {
            _edgeMatrix[i]->resize(_points.size(), false);
        }
    } else if (_points.size() > size) {
        for (std::size_t i = 0; i < _points.size() - size; i++) {
            auto row = std::make_shared<std::vector<bool>>(_points.size(), false);
            _edgeMatrix.push_back(row);
        }
        for (std::size_t i = 0; i < size; i++) {
            _edgeMatrix[i]->resize(_points.size(), false);
        }
    }
}

void MatrixStructure::AddEdge(const Edge& edge) {
    *(_edgeMatrix[edge.GetFirst()]->begin() + edge.GetSecond()) = true;
    *(_edgeMatrix[edge.GetSecond()]->begin() + edge.GetFirst()) = true;
}

ModelStructurePtr MatrixStructure::Clone() const {
    auto cloned = std::make_shared<MatrixStructure>();
    cloned->SetCenter(_center);
    for (const Point& point : _points) {
        cloned->AddPoint(point);
    }
    cloned->_edgeMatrix = _edgeMatrix;

    return cloned;
}
