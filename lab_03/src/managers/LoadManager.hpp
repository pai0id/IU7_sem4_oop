/**
 * Project Untitled
 */


#ifndef _LOADMANAGER_H
#define _LOADMANAGER_H

#include "../loader/LoaderSolution.hpp"
#include "../build/DirectorSolution.hpp"
#include "../scene/BaseObject.hpp"
#include <cstdlib>
#include <memory>

/// ID директоров
#define LISTCARCASMODELDIRECTORCREATOR_ID 1
#define MATRIXCARCASMODELDIRECTORCREATOR_ID 2

/// ID загрузчиков
#define TXTCARCASMODELLOADERCREATOR_ID 1
#define SQLITECARCASMODELLOADERCREATOR_ID 2

class LoadManager {
public:
    LoadManager();
    ~LoadManager() = default;

    std::shared_ptr<BaseObject> LoadCarcasModelFile(std::size_t directorID, std::size_t laoderID, const char *filename);

protected:
    DirectorSolution _dsolution;
    LoaderSolution _lsolution;
};

#endif //_LOADMANAGER_H
