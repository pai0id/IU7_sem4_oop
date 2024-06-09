#pragma once
#include "BaseReader.h"
#include "BaseReaderCreator.h"
#include "concept.h"
#include <map>

class ReaderSolution {
    public:
        ReaderSolution();
        ReaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseReaderCreator>>> list);

        void Register(std::size_t index, std::shared_ptr<BaseReaderCreator> creator);
        bool Check(std::size_t index);

        template <typename ConReaderCreator>
        requires Derivative<ConReaderCreator, BaseReaderCreator>
        std::shared_ptr<ConReaderCreator> Create(std::size_t index);

        ~ReaderSolution();

    private:
        std::map<size_t, std::shared_ptr<BaseReaderCreator>> _creators;

};

#include "ReaderSolution.hpp"
