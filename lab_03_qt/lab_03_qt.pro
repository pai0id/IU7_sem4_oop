QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++2a
LIBS += -lsqlite3 -lm
OBJECTS_DIR = ./obj

INCLUDEPATH += src/
INCLUDEPATH += src/**
INCLUDEPATH += src/**/**

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/drawer/QTDrawer.cpp \
    src/drawer/QTDrawerCreator.cpp \
    src/drawer/BaseDrawerCreator.cpp \
    src/drawer/BaseDrawer.cpp \
    src/loader/BaseLoader.cpp \
    src/loader/LoaderCreator.cpp \
    src/loader/ModelSqLoader.cpp \
    src/loader/BaseLoaderCreator.cpp \
    src/loader/LoaderSolution.cpp \
    src/loader/ModelTxtLoader.cpp \
    src/loader/CarcasModelLoader.cpp \
    src/exception/baseexception.cpp \
    src/managers/DrawManager.cpp \
    src/managers/LoadManager.cpp \
    src/managers/TransformManager.cpp \
    src/managers/SceneManager.cpp \
    src/visitors/DrawVisitor.cpp \
    src/visitors/TransformVisitor.cpp \
    src/visitors/Visitor.cpp \
    src/transform/TransformAction.cpp \
    src/transform/multMat.cpp \
    src/transform/ScaleAction.cpp \
    src/transform/RotateAction.cpp \
    src/transform/CameraProjectionAction.cpp \
    src/transform/ShiftAction.cpp \
    src/build/DirectorSolution.cpp \
    src/build/BaseCarcasModelBuilder.cpp \
    src/build/MatrixCarcasModelDirector.cpp \
    src/build/BaseCarcasModelDirector.cpp \
    src/build/ListCarcasModelDirector.cpp \
    src/build/MatrixCarcasModelBuilder.cpp \
    src/build/ListCarcasModelBuilder.cpp \
    src/build/Basedirector.cpp \
    src/command/object/CompositeObjectCommand.cpp \
    src/command/object/RotateObjectCommand.cpp \
    src/command/object/ShiftObjectCommand.cpp \
    src/command/object/ScaleObjectCommand.cpp \
    src/command/object/BaseObjectCommand.cpp \
    src/command/object/RemoveObjectCommand.cpp \
    src/command/BaseCommand.cpp \
    src/command/draw/BaseDrawCommand.cpp \
    src/command/draw/DrawSceneQtCommand.cpp \
    src/command/load/MatrixLoadCommand.cpp \
    src/command/load/BaseLoadCommand.cpp \
    src/command/load/ListLoadCommand.cpp \
    src/command/load/BaseLoadCommandDecorator.cpp \
    src/command/load/TxtLoadCommandDecorator.cpp \
    src/command/load/SqliteLoadCommandDecorator.cpp \
    src/command/camera/AddCameraCommand.cpp \
    src/command/camera/RemoveCameraCommand.cpp \
    src/command/camera/BaseCameraCommand.cpp \
    src/command/camera/SetCameraCommand.cpp \
    src/command/scene/GetObjectIDsSceneCommand.cpp \
    src/command/scene/BaseSceneCommand.cpp \
    src/command/scene/GetCameraIDsSceneCommand.cpp \
    src/command/scene/ClearSceneCommand.cpp \
    src/Facade.cpp \
    src/scene/Composite.cpp \
    src/scene/Point.cpp \
    src/scene/CenterStrategy.cpp \
    src/scene/LinkDotStructure.cpp \
    src/scene/InvisibleObject.cpp \
    src/scene/VisibleObject.cpp \
    src/scene/Scene.cpp \
    src/scene/MatrixStructure.cpp \
    src/scene/Edge.cpp \
    src/scene/Camera.cpp \
    src/scene/CarcasModel.cpp \
    src/scene/BaseModel.cpp \
    src/scene/CarcasModelStructure.cpp \
    src/scene/BaseObject.cpp


HEADERS += \
    mainwindow.h \
    src/concepts/concept.h \
    src/command/object/RotateObjectCommand.h \
    src/command/object/ShiftObjectCommand.h \
    src/command/object/ScaleObjectCommand.h \
    src/command/object/CompositeObjectCommand.h \
    src/command/object/BaseObjectCommand.h \
    src/command/object/RemoveObjectCommand.h \
    src/command/draw/DrawSceneQtCommand.h \
    src/command/draw/BaseDrawCommand.h \
    src/command/load/SqliteLoadCommandDecorator.h \
    src/command/load/BaseLoadCommandDecorator.h \
    src/command/load/BaseLoadCommand.h \
    src/command/load/ListLoadCommand.h \
    src/command/load/TxtLoadCommandDecorator.h \
    src/command/load/MatrixLoadCommand.h \
    src/command/camera/RemoveCameraCommand.h \
    src/command/camera/BaseCameraCommand.h \
    src/command/camera/AddCameraCommand.h \
    src/command/camera/SetCameraCommand.h \
    src/command/scene/GetCameraIDsSceneCommand.h \
    src/command/scene/ClearSceneCommand.h \
    src/command/scene/BaseSceneCommand.h \
    src/command/scene/GetObjectIDsSceneCommand.h \
    src/drawer/QTDrawerCreator.hpp \
    src/drawer/BaseDrawer.hpp \
    src/drawer/BaseDrawerCreator.hpp \
    src/drawer/QTDrawer.hpp \
    src/loader/BaseLoader.hpp \
    src/loader/BaseLoaderCreator.hpp \
    src/loader/LoaderSolution.hpp \
    src/loader/LoaderCreator.hpp \
    src/loader/ModelSqLoader.hpp \
    src/loader/ModelTxtLoader.hpp \
    src/loader/CarcasModelLoader.hpp \
    src/exception/baseexception.hpp \
    src/exception/sqlitereaderexception.hpp \
    src/exception/txtreaderexception.hpp \
    src/exception/solutionexception.hpp \
    src/exception/directorexception.hpp \
    src/exception/modelexception.hpp \
    src/exception/managerexception.hpp \
    src/managers/DrawManager.hpp \
    src/managers/SceneManager.hpp \
    src/managers/TransformManager.hpp \
    src/managers/LoadManager.hpp \
    src/visitors/TransformVisitor.hpp \
    src/visitors/Visitor.hpp \
    src/visitors/DrawVisitor.hpp \
    src/transform/RotateAction.hpp \
    src/transform/TransformAction.hpp \
    src/transform/multMat.hpp \
    src/transform/CameraProjectionAction.hpp \
    src/transform/ShiftAction.hpp \
    src/transform/ScaleAction.hpp \
    src/build/MatrixCarcasModelBuilder.hpp \
    src/build/ListCarcasModelBuilder.hpp \
    src/build/DirectorCreator.hpp \
    src/build/BaseCarcasModelBuilder.hpp \
    src/build/DirectorSolution.hpp \
    src/build/BaseDirectorCreator.hpp \
    src/build/BaseDirector.hpp \
    src/build/BaseCarcasModelDirector.hpp \
    src/build/MatrixCarcasModelDirector.hpp \
    src/build/ListCarcasModelDirector.hpp \
    src/command/BaseCommand.hpp \
    src/Facade.hpp \
    src/scene/Composite.hpp \
    src/scene/InvisibleObject.hpp \
    src/scene/LinkDotStructure.hpp \
    src/scene/Camera.hpp \
    src/scene/VisibleObject.hpp \
    src/scene/BaseObject.hpp \
    src/scene/CarcasModelStructure.hpp \
    src/scene/BaseModel.hpp \
    src/scene/Edge.hpp \
    src/scene/Point.hpp \
    src/scene/CenterStrategy.hpp \
    src/scene/Scene.hpp \
    src/scene/MatrixStructure.hpp \
    src/scene/CarcasModel.hpp


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
