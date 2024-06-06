#ifndef _MATRIXCARCMODELDIRECTOR_H
#define _MATRIXCARCMODELDIRECTOR_H

#include "BaseCarcasModelDirector.hpp"

class MatrixCarcasModelDirector : public BaseCarcasModelDirector {
    public:
        MatrixCarcasModelDirector(std::shared_ptr<CarcasModelLoader> Loader);
        virtual ~MatrixCarcasModelDirector() = default;
};

#endif
