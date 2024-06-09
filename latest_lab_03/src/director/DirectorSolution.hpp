#include "DirectorSolution.h"
#include "solutionexception.h"

template <typename ConDirectorCreator>
requires Derivative<ConDirectorCreator, BaseDirectorCreator>
std::shared_ptr<ConDirectorCreator> DirectorSolution::Create(std::size_t index) {
    if (Check(index)) {
        auto creator = std::dynamic_pointer_cast<ConDirectorCreator>(_creators[index]);
        if (!creator) {
            time_t now = time(nullptr);
            throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }
        return creator;
    }
    time_t now = time(nullptr);
    throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}
