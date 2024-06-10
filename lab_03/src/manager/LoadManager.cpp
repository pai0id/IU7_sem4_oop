#include "LoadManager.h"
#include "managerexception.h"
#include "ReaderCreator.h"

LoadManager::LoadManager() {
    _dsolution.Register(LISTBONEMODELDIRECTORCREATOR_ID, std::make_shared<ListBoneModelDirectorCreator>());
    _dsolution.Register(MATRIXBONEMODELDIRECTORCREATOR_ID, std::make_shared<MatrixBoneModelDirectorCreator>());

    _rsolution.Register(TXTBONEMODELREADERCREATOR_ID, std::make_shared<TxtBoneModelReaderCreator>());
    _rsolution.Register(SQLITEBONEMODELREADERCREATOR_ID, std::make_shared<SqliteBoneModelReaderCreator>());
}


std::shared_ptr<Object> LoadManager::LoadBoneModelFile(std::size_t directorID, std::size_t ReaderID, std::string filename) {  // done
    auto directorCr = _dsolution.Create<BoneModelDirectorCreator_t>(directorID);
    auto readerCr = _rsolution.Create<BoneModelReaderCreator_t>(ReaderID);      // Done

    std::shared_ptr<BoneModelReader> boneModelReader = readerCr->Create(std::move(filename));
    std::shared_ptr<BaseBoneModelDirector> boneModelDirector = directorCr->Create(std::move(boneModelReader));
    return boneModelDirector->Create();
};
