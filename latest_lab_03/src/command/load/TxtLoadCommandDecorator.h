#pragma once
#include "BaseLoadCommandDecorator.h"

class TxtLoadCommandDecorator : public BaseLoadCommandDecorator {
    public:
        virtual ~TxtLoadCommandDecorator() = default;
        TxtLoadCommandDecorator() = delete;
        TxtLoadCommandDecorator(BaseLoadCommand &command, std::string filename);
        virtual void Execute();
    protected:
        std::string _filename;
};
