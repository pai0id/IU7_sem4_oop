#pragma once
#include "../BaseCommand.hpp"

class BaseSceneCommand : public BaseCommand {
    public:
        BaseSceneCommand() = default;
        virtual ~BaseSceneCommand() = 0;

};
