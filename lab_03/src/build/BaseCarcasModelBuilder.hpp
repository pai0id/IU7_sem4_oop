#ifndef _BASECARCMODELBUILDER_H
#define _BASECARCMODELBUILDER_H

#include "../scene/CarcasModel.hpp"
#include "../scene/CarcasModelStructure.hpp"


class BaseCarcasModelBuilder {
public:
    BaseCarcasModelBuilder() = default;

    virtual ~BaseCarcasModelBuilder() = 0;

    virtual std::shared_ptr<CarcasModel> Get();
    virtual void BuildPoint(const Point &p);
    virtual void BuildEdge(const Edge &edge);
    virtual void BuildCenter(const Point &center);
    virtual bool IsBuilt();
protected:
    std::shared_ptr<CarcasModelStructure> _model;
};

#endif
