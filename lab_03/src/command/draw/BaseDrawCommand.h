#pragma once
#include "../BaseCommand.hpp"

class BaseDrawCommand : public BaseCommand {
    public:
        BaseDrawCommand() = default;
        virtual ~BaseDrawCommand() = 0;
};
