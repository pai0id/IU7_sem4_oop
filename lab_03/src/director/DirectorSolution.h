#pragma once
#include "BaseDirectorCreator.h"
#include "DirectorCreator.h"
#include "concept.h"
#include <map>

class DirectorSolution {
    public:
        DirectorSolution();
        DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list);

        void Register(std::size_t index, std::shared_ptr<BaseDirectorCreator> creator);
        bool Check(std::size_t index);

        template <typename ConDirectorCreator>
        requires Derivative<ConDirectorCreator, BaseDirectorCreator>
        std::shared_ptr<ConDirectorCreator> Create(std::size_t index);

        ~DirectorSolution();

    private:
        std::map<size_t, std::shared_ptr<BaseDirectorCreator>> _creators;
};

#include "DirectorSolution.hpp"
