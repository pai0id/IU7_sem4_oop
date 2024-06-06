/**
 * Project Untitled
 */


#ifndef _LOADERSOLUTION_H
#define _LOADERSOLUTION_H

#include "BaseLoader.h"
#include "BaseLoaderCreator.h"
#include <memory>
#include <map>

class LoaderSolution {
public:
    LoaderSolution();
    LoaderSolution(std::initializer_list<std::pair<size_t, std::shared_ptr<BaseLoaderCreator>>> list);

    void Register(std::size_t index, std::shared_ptr<BaseLoaderCreator> creator);
    bool Check(std::size_t index);
    std::shared_ptr<BaseLoaderCreator> Create(std::size_t index);

    ~LoaderSolution();

private:
    std::map<size_t, std::shared_ptr<BaseLoaderCreator>> _creators;
};

#endif //_LOADERSOLUTION_H
