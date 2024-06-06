/**
 * Project Untitled
 */


#include "ModelTxtLoader.hpp"
#include "../exception/txtreaderexception.hpp"

ModelTxtLoader::ModelTxtLoader(const char* filename) : _fname(filename), _centerStrategy(std::make_shared<ClassicCenterStrategy>()) {}

ModelTxtLoader::~ModelTxtLoader() {
    if (IsOpen()) {
        Close();
    }
}

bool ModelTxtLoader::IsOpen() {
    return _file.is_open();
}

void ModelTxtLoader::Open() {
    if (_file.is_open())
        return;
    _file.open(_fname);
    if (!_file) {
        throw TxtNoFileException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
}

void ModelTxtLoader::Close() {
    if (!_file.is_open())
        return
    _file.close();
}

std::vector<Point> ModelTxtLoader::ReadPoints() {
    if (!IsOpen())
        return std::vector<Point>();
    std::vector<Point> points;
    _file.clear();
    _file.seekg(0, std::ios::beg);

    int size = 0;
    _file >> size;
    points.resize(size);
    double x, y, z;
    for (int i = 0; i < size; i++) {
        _file >> x >> y >> z;
        if (!_file) {
            throw TxtNoFileException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }
        points[i].SetX(x);
        points[i].SetY(y);
        points[i].SetZ(z);

    }

    return points;
}

std::vector<Edge> ModelTxtLoader::ReadEdges() {
    if (!IsOpen())
        return std::vector<Edge>();
    std::vector<Edge> edges;
    ReadPoints();

    int size = 0;
    _file >> size;
    edges.resize(size);
    for (int i = 0; i < size; i++) {
        int a, b;
        _file >> a >> b;
        if (!_file) {
            throw TxtNoFileException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }
        edges[i].SetFirst(a - 1);
        edges[i].SetSecond(b - 1);
    }
    return edges;
}


Point ModelTxtLoader::ReadCenter() {
    std::vector<Point> points = ReadPoints();
    return _centerStrategy->CenterAlgorithm(points);
}

