/**
 * Project Untitled
 */

#include "LoaderSolution.hpp"
#include "../exception/solutionexception.hpp"

LoaderSolution::LoaderSolution() : _creators(std::map<std::size_t, std::shared_ptr<BaseLoaderCreator>>()) {}

LoaderSolution::~LoaderSolution() {}

LoaderSolution::LoaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseLoaderCreator>>> list) {
    for (const auto& pair : list) {
        _creators[pair.first] = pair.second;
    }
}


bool LoaderSolution::Check(std::size_t index) {
    return _creators.find(index)!= _creators.end();
}

std::shared_ptr<BaseLoaderCreator> LoaderSolution::Create(std::size_t index) {
    if (Check(index)) {
        return _creators[index];
    }
    throw SolutionNotFoundException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}


void LoaderSolution::Register(std::size_t index, std::shared_ptr<BaseLoaderCreator> creator) {
    if (Check(index)) {
        throw SolutionAlreadyInException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    _creators[index] = creator;
}
