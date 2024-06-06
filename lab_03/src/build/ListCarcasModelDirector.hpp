#ifndef _LISTCARCMODELDIRECTOR_H
#define _LISTCARCMODELDIRECTOR_H

#include "BaseCarcasModelDirector.hpp"

class ListCarcasModelDirector : public BaseCarcasModelDirector {
    public:
        ListCarcasModelDirector(std::shared_ptr<CarcasModelLoader> Loader);
        virtual ~ListCarcasModelDirector() = default;
};

#endif
