/**
 * Project Untitled
 */


#ifndef _QTDRAWER_H
#define _QTDRAWER_H

#include "BaseDrawer.h"
#include <QGraphicsScene>

class QTDrawer: public BaseDrawer {
public:
    QTDrawer() = delete;
    QTDrawer(QGraphicsScene* scene);
    virtual ~QTDrawer() = default;
    virtual void DrawLine(const Point& p1, const Point& p2);
    virtual void Clear();
private:
    QGraphicsScene* _scene;
};

#endif //_SDLDRAWER_H
