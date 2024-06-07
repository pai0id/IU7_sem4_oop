/**
 * Project Untitled
 */


#ifndef _MODELSQLOADER_H
#define _MODELSQLOADER_H

#include "CarcasModelLoader.hpp"
#include "../scene/CenterStrategy.hpp"
#include <sqlite3.h>
#include <memory>

class ModelSqliteLoader: public CarcasModelLoader {
public:
    ModelSqliteLoader(const char* filename);
    virtual ~ModelSqliteLoader();

    virtual void Open();
    virtual void Close();
    virtual bool IsOpen();

    virtual std::vector<Point> ReadPoints();
    virtual std::vector<Edge> ReadEdges();
    virtual Point ReadCenter();

protected:
    const char* _fname;
    sqlite3 * _db;
    std::shared_ptr<BaseCenterStrategy> _centerStrategy;
};

#endif //_MODELSVGLOADER_H
