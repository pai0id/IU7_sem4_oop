QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

INCLUDEPATH += src/
INCLUDEPATH += src/**
INCLUDEPATH += src/**/**

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ./src/Facade.cpp \
    ./src/build/BaseCarcasDirector.cpp \
    ./src/build/BaseDirector.cpp \
    ./src/build/BaseLinkDotModelBuilder.cpp \
    ./src/build/BaseMatrixModelBuilder.cpp \
    ./src/build/DirectorSolution.cpp \
    ./src/build/LinkDotDirector.cpp \
    ./src/build/LinkDotModelBuilder.cpp \
    ./src/build/MatrixDirector.cpp \
    ./src/build/MatrixModelBuilder.cpp \
    ./src/commands/BaseCommand.cpp \
    ./src/commands/camera/AddCameraCommand.cpp \
    ./src/commands/camera/BaseCameraCommand.cpp \
    ./src/commands/camera/MoveCameraCommand.cpp \
    ./src/commands/camera/RemoveCameraCommand.cpp \
    ./src/commands/camera/RotateCameraCommand.cpp \
    ./src/commands/model/BaseModelCommand.cpp \
    ./src/commands/model/LoadModelCommand.cpp \
    ./src/commands/model/MoveModelCommand.cpp \
    ./src/commands/model/RemoveModelCommand.cpp \
    ./src/commands/model/RotateModelCommand.cpp \
    ./src/commands/model/ScaleModelCommand.cpp \
    ./src/commands/scene/BaseSceneCommand.cpp \
    ./src/commands/scene/ClearSceneCommand.cpp \
    ./src/commands/scene/DrawSceneCommand.cpp \
    ./src/commands/scene/LoadSceneCommand.cpp \
    ./src/drawer/BaseDrawer.cpp \
    ./src/drawer/BaseDrawerCreator.cpp \
    ./src/drawer/SDLDrawer.cpp \
    ./src/drawer/SDLDrawerCreator.cpp \
    ./src/loader/BaseLoader.cpp \
    ./src/loader/BaseLoaderCreator.cpp \
    ./src/loader/LoaderSolution.cpp \
    ./src/loader/ModelSvgLoader.cpp \
    ./src/loader/ModelSvgLoaderCreator.cpp \
    ./src/loader/ModelTxtLoader.cpp \
    ./src/loader/ModelTxtLoaderCreator.cpp \
    ./src/managers/DrawManager.cpp \
    ./src/managers/LoadManager.cpp \
    ./src/managers/MementoManager.cpp \
    ./src/managers/SceneManager.cpp \
    ./src/managers/TransformManager.cpp \
    ./src/memento/MementoCaretaker.cpp \
    ./src/memento/Memento.cpp \
    ./src/memento/SceneMementoCaretaker.cpp \
    ./src/memento/SceneMemento.cpp \
    ./src/scene/BaseModel.cpp \
    ./src/scene/BaseObject.cpp \
    ./src/scene/Camera.cpp \
    ./src/scene/LinkDotData.cpp \
    ./src/scene/CarcasModel.cpp \
    ./src/scene/Composite.cpp \
    ./src/scene/Edge.cpp \
    ./src/scene/InvisibleObject.cpp \
    ./src/scene/LinkDotStructure.cpp \
    ./src/scene/MatrixData.cpp \
    ./src/scene/MatrixModel.cpp \
    ./src/scene/MatrixStructure.cpp \
    ./src/scene/ModelStructure.cpp \
    ./src/scene/Point.cpp \
    ./src/scene/Scene.cpp \
    ./src/scene/VisibleObject.cpp \
    ./src/scene/CenterStrategy.cpp \
    ./src/visitors/DrawVisitor.cpp \
    ./src/visitors/MoveVisitor.cpp \
    ./src/visitors/RotateVisitor.cpp \
    ./src/visitors/ScaleVisitor.cpp \
    ./src/visitors/Visitor.cpp \
    ./src/transform/CameraProjectionAction.cpp \
    ./src/transform/RotateAction.cpp \
    ./src/transform/ScaleAction.cpp \
    ./src/transform/ShiftAction.cpp \
    ./src/transform/TransformAction.cpp



HEADERS += \
    mainwindow.h \
    ./src/Facade.h \
    ./src/build/BaseCarcasDirector.h \
    ./src/build/BaseDirector.h \
    ./src/build/BaseLinkDotModelBuilder.h \
    ./src/build/BaseMatrixModelBuilder.h \
    ./src/build/DirectorSolution.h \
    ./src/build/LinkDotDirector.h \
    ./src/build/LinkDotModelBuilder.h \
    ./src/build/MatrixDirector.h \
    ./src/build/MatrixModelBuilder.h \
    ./src/commands/BaseCommand.h \
    ./src/commands/camera/AddCameraCommand.h \
    ./src/commands/camera/BaseCameraCommand.h \
    ./src/commands/camera/MoveCameraCommand.h \
    ./src/commands/camera/RemoveCameraCommand.h \
    ./src/commands/camera/RotateCameraCommand.h \
    ./src/commands/model/BaseModelCommand.h \
    ./src/commands/model/LoadModelCommand.h \
    ./src/commands/model/MoveModelCommand.h \
    ./src/commands/model/RemoveModelCommand.h \
    ./src/commands/model/RotateModelCommand.h \
    ./src/commands/model/ScaleModelCommand.h \
    ./src/commands/scene/BaseSceneCommand.h \
    ./src/commands/scene/ClearSceneCommand.h \
    ./src/commands/scene/DrawSceneCommand.h \
    ./src/commands/scene/LoadSceneCommand.h \
    ./src/drawer/BaseDrawerCreator.h \
    ./src/drawer/BaseDrawer.h \
    ./src/drawer/SDLDrawerCreator.h \
    ./src/drawer/SDLDrawer.h \
    ./src/loader/BaseLoaderCreator.h \
    ./src/loader/BaseLoader.h \
    ./src/loader/LoaderSolution.h \
    ./src/loader/ModelSvgLoaderCreator.h \
    ./src/loader/ModelSvgLoader.h \
    ./src/loader/ModelTxtLoaderCreator.h \
    ./src/loader/ModelTxtLoader.h \
    ./src/managers/DrawManager.h \
    ./src/managers/LoadManager.h \
    ./src/managers/MementoManager.h \
    ./src/managers/SceneManager.h \
    ./src/managers/TransformManager.h \
    ./src/memento/MementoCaretaker.h \
    ./src/memento/Memento.h \
    ./src/memento/SceneMementoCaretaker.h \
    ./src/memento/SceneMemento.h \
    ./src/scene/BaseModel.h \
    ./src/scene/BaseObject.h \
    ./src/scene/Camera.h \
    ./src/scene/LinkDotData.h \
    ./src/scene/CarcasModel.h \
    ./src/scene/Composite.h \
    ./src/scene/Edge.h \
    ./src/scene/InvisibleObject.h \
    ./src/scene/LinkDotStructure.h \
    ./src/scene/MatrixData.h \
    ./src/scene/MatrixModel.h \
    ./src/scene/MatrixStructure.h \
    ./src/scene/ModelStructure.h \
    ./src/scene/Point.h \
    ./src/scene/Scene.h \
    ./src/scene/VisibleObject.h \
    ./src/scene/CenterStrategy.h \
    ./src/visitors/DrawVisitor.h \
    ./src/visitors/MoveVisitor.h \
    ./src/visitors/RotateVisitor.h \
    ./src/visitors/ScaleVisitor.h \
    ./src/visitors/Visitor.h \
    ./src/transform/CameraProjectionAction.h \
    ./src/transform/RotateAction.h \
    ./src/transform/ScaleAction.h \
    ./src/transform/ShiftAction.h \
    ./src/transform/TransformAction.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
