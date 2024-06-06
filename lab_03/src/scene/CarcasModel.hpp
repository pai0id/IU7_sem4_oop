/**
 * Project Untitled
 */


#ifndef _CARCASMODEL_H
#define _CARCASMODEL_H

#include "BaseModel.hpp"
#include "CarcasModelStructure.hpp"
#include "../visitors/DrawVisitor.hpp"
#include "../visitors/TransformVisitor.hpp"

class CarcasModel : public BaseModel, public VisitableObject<CarcasModel> {
    using VisitableObject<CarcasModel>::VisitableObject;
    friend class DrawVisitor;
    friend class TransformVisitor;
public:
    CarcasModel();
    explicit CarcasModel(ModelStructurePtr);
    explicit CarcasModel(const CarcasModel& other);
    ~CarcasModel() = default;

    virtual Point GetCenter() const;

protected:
    ModelStructurePtr _model;
};

#endif //_CARCASMODEL_H
