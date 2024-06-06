/**
 * Project Untitled
 */


#ifndef _QTDRAWERCREATOR_H
#define _QTDRAWERCREATOR_H

#include "BaseDrawerCreator.h"
#include <QGraphicsScene>

class QTDrawerCreator: public BaseDrawerCreator {
public:
    QTDrawerCreator(QGraphicsScene* scene);
    QTDrawerCreator() = delete;
    ~QTDrawerCreator() = default;

    std::shared_ptr<BaseDrawer> Create();

private:
    QGraphicsScene* _scene;
};

#endif //_SDLDRAWERCREATOR_H
