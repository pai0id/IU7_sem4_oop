/**
 * Project Untitled
 */


#ifndef _CARCASMODEL_H
#define _CARCASMODEL_H

#include "BaseModel.h"
#include "CarcasModelStructure.h"
#include "../visitors/DrawVisitor.h"
#include "../visitors/MoveVisitor.h"
#include "../visitors/RotateVisitor.h"
#include "../visitors/ScaleVisitor.h"

class CarcasModel : public BaseModel, public VisitableObject<CarcasModel> {
    using VisitableObject<CarcasModel>::VisitableObject;
    friend class DrawVisitor;
    friend class MoveVisitor;
    friend class RotateVisitor;
    friend class ScaleVisitor;
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
