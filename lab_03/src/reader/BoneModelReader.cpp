#include "BoneModelReader.h"
#include "FindCenter.h"

Point BoneModelReader::ReadCenter() {
    std::vector<Point> points = ReadPoints();
    return FindCenter(points);
}
