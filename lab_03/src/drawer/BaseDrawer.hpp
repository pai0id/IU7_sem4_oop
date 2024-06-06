/**
 * Project Untitled
 */


#ifndef _BASEDRAWER_H
#define _BASEDRAWER_H

#include "../scene/Point.hpp"

class BaseDrawer {
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = 0;

    virtual void DrawLine(const Point& p1, const Point& p2) = 0;
    virtual void Clear() = 0;
};

#endif //_BASEDRAWER_H
