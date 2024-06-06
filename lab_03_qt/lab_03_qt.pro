QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20
LIBS += sqlite3

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
    ./src/build/BaseCarcasModelBuilder.cpp \
    ./src/build/BaseCarcasModelDirector.cpp \
    ./src/build/Basedirector.cpp \
    ./src/build/DirectorSolution.cpp \
    ./src/build/ListCarcasModelBuilder.cpp \
    ./src/build/ListCarcasModelDirector.cpp \
    ./src/build/MatrixCarcasModelBuilder.cpp \
    ./src/build/MatrixCarcasModelDirector.cpp \
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
    ./src/drawer/QTDrawer.cpp \
    ./src/drawer/QTDrawerCreator.cpp \
    ./src/loader/BaseLoader.cpp \
    ./src/loader/BaseLoaderCreator.cpp \
    ./src/loader/LoaderSolution.cpp \
    ./src/loader/ModelSqLoader.cpp \
    ./src/loader/ModelTxtLoader.cpp \
    ./src/managers/DrawManager.cpp \
    ./src/managers/LoadManager.cpp \
    ./src/managers/SceneManager.cpp \
    ./src/managers/TransformManager.cpp \
    ./src/scene/BaseModel.cpp \
    ./src/scene/BaseObject.cpp \
    ./src/scene/Camera.cpp \
    ./src/scene/CarcasModel.cpp \
    ./src/scene/Composite.cpp \
    ./src/scene/Edge.cpp \
    ./src/scene/InvisibleObject.cpp \
    ./src/scene/LinkDotStructure.cpp \
    ./src/scene/MatrixStructure.cpp \
    ./src/scene/CarcasModelStructure.cpp \
    ./src/scene/Point.cpp \
    ./src/scene/Scene.cpp \
    ./src/scene/VisibleObject.cpp \
    ./src/scene/CenterStrategy.cpp \
    ./src/visitors/DrawVisitor.cpp \
    ./src/visitors/TransformVisitor.cpp \
    ./src/visitors/Visitor.cpp \
    ./src/transform/CameraProjectionAction.cpp \
    ./src/transform/RotateAction.cpp \
    ./src/transform/ScaleAction.cpp \
    ./src/transform/ShiftAction.cpp \
    ./src/transform/TransformAction.cpp \
    ./src/transform/multMat.cpp \
    ./src/loader/LoaderCreator.cpp

HEADERS += \
    mainwindow.h \
    ./src/Facade.hpp \
    ./src/build/BaseCarcasModelBuilder.hpp \
    ./src/build/BaseCarcasModelDirector.hpp \
    ./src/build/Basedirector.hpp \
    ./src/build/DirectorSolution.hpp \
    ./src/build/ListCarcasModelBuilder.hpp \
    ./src/build/ListCarcasModelDirector.hpp \
    ./src/build/MatrixCarcasModelBuilder.hpp \
    ./src/build/MatrixCarcasModelDirector.hpp \
    ./src/commands/BaseCommand.hpp \
    ./src/commands/camera/AddCameraCommand.hpp \
    ./src/commands/camera/BaseCameraCommand.hpp \
    ./src/commands/camera/MoveCameraCommand.hpp \
    ./src/commands/camera/RemoveCameraCommand.hpp \
    ./src/commands/camera/RotateCameraCommand.hpp \
    ./src/commands/model/BaseModelCommand.hpp \
    ./src/commands/model/LoadModelCommand.hpp \
    ./src/commands/model/MoveModelCommand.hpp \
    ./src/commands/model/RemoveModelCommand.hpp \
    ./src/commands/model/RotateModelCommand.hpp \
    ./src/commands/model/ScaleModelCommand.hpp \
    ./src/commands/scene/BaseSceneCommand.hpp \
    ./src/commands/scene/ClearSceneCommand.hpp \
    ./src/commands/scene/DrawSceneCommand.hpp \
    ./src/commands/scene/LoadSceneCommand.hpp \
    ./src/drawer/BaseDrawerCreator.hpp \
    ./src/drawer/BaseDrawer.hpp \
    ./src/drawer/QTDrawerCreator.hpp \
    ./src/drawer/QTDrawer.hpp \
    ./src/loader/BaseLoaderCreator.hpp \
    ./src/loader/BaseLoader.hpp \
    ./src/loader/LoaderSolution.hpp \
    ./src/loader/ModelSqLoader.hpp \
    ./src/loader/ModelTxtLoader.hpp \
    ./src/managers/DrawManager.hpp \
    ./src/managers/LoadManager.hpp \
    ./src/managers/SceneManager.hpp \
    ./src/managers/TransformManager.hpp \
    ./src/scene/BaseModel.hpp \
    ./src/scene/BaseObject.hpp \
    ./src/scene/Camera.hpp \
    ./src/scene/CarcasModel.hpp \
    ./src/scene/Composite.hpp \
    ./src/scene/Edge.hpp \
    ./src/scene/InvisibleObject.hpp \
    ./src/scene/LinkDotStructure.hpp \
    ./src/scene/MatrixStructure.hpp \
    ./src/scene/CarcasModelStructure.hpp \
    ./src/scene/Point.hpp \
    ./src/scene/Scene.hpp \
    ./src/scene/VisibleObject.hpp \
    ./src/scene/CenterStrategy.hpp \
    ./src/visitors/DrawVisitor.hpp \
    ./src/visitors/TransformVisitor.hpp \
    ./src/visitors/Visitor.hpp \
    ./src/transform/CameraProjectionAction.hpp \
    ./src/transform/RotateAction.hpp \
    ./src/transform/ScaleAction.hpp \
    ./src/transform/ShiftAction.hpp \
    ./src/transform/TransformAction.hpp \
    ./src/transform/multMat.hpp \
    ./src/loader/LoaderCreator.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
