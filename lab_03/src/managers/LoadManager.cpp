/**
 * Project Untitled
 */


#include "LoadManager.hpp"
#include "../exception/managerexception.hpp"
#include "../loader/LoaderCreator.hpp"

LoadManager::LoadManager() {
    _dsolution.Register(LISTCARCASMODELDIRECTORCREATOR_ID, std::make_shared<ListCarcasModelDirectorCreator>());
    _dsolution.Register(MATRIXCARCASMODELDIRECTORCREATOR_ID, std::make_shared<MatrixCarcasModelDirectorCreator>());

    _lsolution.Register(TXTCARCASMODELLOADERCREATOR_ID, std::make_shared<TxtCarcasModelLoaderCreator>());
    _lsolution.Register(SQLITECARCASMODELLOADERCREATOR_ID, std::make_shared<SqliteCarcasModelLoaderCreator>());
}


std::shared_ptr<BaseObject> LoadManager::LoadCarcasModelFile(std::size_t directorID, std::size_t LoaderID, const char* filename) {
    std::shared_ptr<BaseDirectorCreator> absDirectorCr = _dsolution.Create(directorID);
    std::shared_ptr<BaseLoaderCreator> absLoaderCr = _lsolution.Create(LoaderID);

    std::shared_ptr<CarcasModelDirectorCreator_t> CarcasModelDirectorCr = std::dynamic_pointer_cast<CarcasModelDirectorCreator_t>(absDirectorCr);
    if (CarcasModelDirectorCr == nullptr) {
        throw LoadManagerWrongDirectorException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<CarcasModelLoaderCreator_t> CarcasModelLoaderCr = std::dynamic_pointer_cast<CarcasModelLoaderCreator_t>(absLoaderCr);
    if (CarcasModelLoaderCr == nullptr) {
        throw LoadManagerWrongLoaderException(__FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<CarcasModelLoader> CarcasModelLoader = CarcasModelLoaderCr->Create(std::move(filename));
    std::shared_ptr<BaseCarcasModelDirector> CarcasModelDirector = CarcasModelDirectorCr->Create(std::move(CarcasModelLoader));
    CarcasModelDirector->Create();
    return CarcasModelDirector->Get();
};
