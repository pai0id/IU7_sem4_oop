/**
 * Project Untitled
 */


#ifndef _CARCASMODEL_H
#define _CARCASMODEL_H

#include "BaseModel.h"
#include "ModelStructure.h"

class CarcasModel: public BaseModel {
    friend class DrawVisitor;
    public:
        CarcasModel();
        explicit CarcasModel(ModelStructurePtr);
        explicit CarcasModel(const CarcasModel& other);
        ~CarcasModel() = default;

        virtual void Accept(const Visitor& visitor);
        virtual Point GetCenter() const;

    protected:
        ModelStructurePtr _model;
};

#endif //_CARCASMODEL_H
