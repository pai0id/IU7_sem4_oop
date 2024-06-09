#include "ReaderSolution.h"
#include "solutionexception.h"

template <typename ConReaderCreator>
requires Derivative<ConReaderCreator, BaseReaderCreator>
std::shared_ptr<ConReaderCreator> ReaderSolution::Create(std::size_t index) {
    if (Check(index)) {
        auto creator = std::dynamic_pointer_cast<ConReaderCreator>(_creators[index]);
        if (!creator) {
            time_t now = time(nullptr);
            throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
        }
        return creator;
    }
    time_t now = time(nullptr);
    throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}
