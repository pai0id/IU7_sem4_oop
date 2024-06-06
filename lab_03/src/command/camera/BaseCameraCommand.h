#pragma once
#include "../BaseCommand.hpp"
#include "../../scene/Point.hpp"

class BaseCameraCommand : public BaseCommand {
    public:
        BaseCameraCommand() = default;
        virtual ~BaseCameraCommand() = 0;
};
