#ifndef _LISTCARCMODELBUILDER_H
#define _LISTCARCMODELBUILDER_H

#include "../scene/CarcasModel.hpp"
#include "BaseCarcasModelBuilder.hpp"
#include "../scene/LinkDotStructure.hpp"


class ListCarcasModelBuilder : public BaseCarcasModelBuilder {
    public:
        ListCarcasModelBuilder();
        
        virtual ~ListCarcasModelBuilder() = default;
};  

#endif
