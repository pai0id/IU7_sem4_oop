#pragma once
#include "../BaseCommand.hpp"


class BaseObjectCommand : public BaseCommand {
    public:
        BaseObjectCommand() = default;
        virtual ~BaseObjectCommand() = 0;
};
