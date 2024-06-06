#ifndef _BONEMODELLOADER_H
#define _BONEMODELLOADER_H

#include "BaseLoader.h"
#include "../scene/Point.h"
#include "../scene/Edge.h"
#include <vector>

class BoneModelLoader : public BaseLoader {
    public:
        BoneModelLoader() = default;

        virtual ~BoneModelLoader() = 0;

        virtual void Open() = 0;
        virtual void Close() = 0;
        virtual bool IsOpen() = 0;

        virtual std::vector<Point> ReadPoints() = 0;
        virtual std::vector<Edge> ReadEdges() = 0;
        virtual Point ReadCenter() = 0;
};

#endif
