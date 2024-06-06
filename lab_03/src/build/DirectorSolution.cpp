#include "DirectorSolution.hpp"
#include "../exception/solutionexception.hpp"

DirectorSolution::DirectorSolution() : _creators(std::map<std::size_t, std::shared_ptr<BaseDirectorCreator>>()) {}

DirectorSolution::~DirectorSolution() {}

DirectorSolution::DirectorSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseDirectorCreator>>> list) {
    for (const auto& pair : list) {
        _creators[pair.first] = pair.second;
    }
}


bool DirectorSolution::Check(std::size_t index) {
    return _creators.find(index)!= _creators.end();
}

std::shared_ptr<BaseDirectorCreator> DirectorSolution::Create(std::size_t index) {
    if (Check(index)) {
        return _creators[index];
    }
    throw SolutionNotFoundException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}


void DirectorSolution::Register(std::size_t index, std::shared_ptr<BaseDirectorCreator> creator) {
    if (Check(index)) {
        throw SolutionAlreadyInException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    _creators[index] = creator;
}
