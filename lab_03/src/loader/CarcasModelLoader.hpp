#ifndef _CARCASMODELLOADER_H
#define _CARCASMODELLOADER_H

#include "BaseLoader.hpp"
#include "../scene/Point.hpp"
#include "../scene/Edge.hpp"
#include <vector>

class CarcasModelLoader : public BaseLoader {
public:
    CarcasModelLoader() = default;

    virtual ~CarcasModelLoader() = 0;

    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual bool IsOpen() = 0;

    virtual std::vector<Point> ReadPoints() = 0;
    virtual std::vector<Edge> ReadEdges() = 0;
    virtual Point ReadCenter() = 0;
};

#endif
