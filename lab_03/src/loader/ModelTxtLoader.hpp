/**
 * Project Untitled
 */


#ifndef _MODELTXTLOADER_H
#define _MODELTXTLOADER_H

#include "CarcasModelLoader.hpp"
#include "../scene/CenterStrategy.hpp"
#include <fstream>
#include <memory>

class ModelTxtLoader: public CarcasModelLoader {
public:
    ModelTxtLoader(const char* filename);
    virtual ~ModelTxtLoader();


    virtual void Open();
    virtual void Close();
    virtual bool IsOpen();

    virtual std::vector<Point> ReadPoints();
    virtual std::vector<Edge> ReadEdges();
    virtual Point ReadCenter();

protected:
    const char* _fname;
    std::ifstream _file;
    std::shared_ptr<BaseCenterStrategy> _centerStrategy;
};

#endif //_MODELTXTLOADER_H
