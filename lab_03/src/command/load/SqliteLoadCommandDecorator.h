#pragma once
#include "BaseLoadCommandDecorator.h"

class SqliteLoadCommandDecorator : public BaseLoadCommandDecorator {
    public:
        virtual ~SqliteLoadCommandDecorator() = default;
        SqliteLoadCommandDecorator() = delete;
        SqliteLoadCommandDecorator(BaseLoadCommand &command, std::string filename);
        virtual void Execute();
    protected:
        std::string _filename;
};
