QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++2a
LIBS += -lsqlite3 -lm
OBJECTS_DIR = ./obj

TEMPLATE = app
TARGET = app.exe

INCLUDEPATH += \
src/objects \
src/transform_strategy \
src/visitor \
src/square_matrix \
src/exception \
src/builder \
src/reader \
src/director \
src/concepts \
src/manager \
src/scene \
src/drawer \
src/command/ \
src/command/draw \
src/command/load \
src/command/camera \
src/command/scene \
src/command/object \
src/facade \
src/center


# Input
HEADERS += src/builder/BaseBoneModelBuilder.h \
    src/builder/ListBoneModelBuilder.h \
    src/builder/MatrixBoneModelBuilder.h \
    src/concepts/concept.h \
    src/director/BaseBoneModelDirector.h \
    src/director/BaseDirectorCreator.h \
    src/director/BaseDirector.h \
    src/director/DirectorCreator.h \
    src/director/DirectorCreator.hpp \
    src/director/DirectorSolution.h \
    src/director/DirectorSolution.hpp \
    src/director/ListBoneModelDirector.h \
    src/director/MatrixBoneModelDirector.h \
    src/drawer/BaseDrawer.h \
    src/drawer/QtDrawer.h \
    src/drawer/BaseDrawerCreator.h \
    src/drawer/QtDrawerCreator.h \
    src/exception/baseexception.h \
    src/exception/directorexception.h \
    src/exception/managerexception.h \
    src/exception/matrixexception.h \
    src/exception/modelexception.h \
    src/exception/solutionexception.h \
    src/exception/sqlitereaderexception.h \
    src/exception/txtreaderexception.h \
    src/manager/LoadManager.h \
    src/manager/SceneManager.h \
    src/manager/DrawManager.h \
    src/manager/DrawManager.hpp \
    src/objects/BaseModel.h \
    src/objects/BoneModel.h \
    src/objects/Camera.h \
    src/objects/Composite.h \
    src/objects/Edge.h \
    src/objects/InvisibleObject.h \
    src/objects/ListModelStructure.h \
    src/objects/MatrixModelStructure.h \
    src/objects/ModelStructure.h \
    src/objects/Object.h \
    src/objects/Point.h \
    src/objects/VisibleObject.h \
    src/reader/BaseReaderCreator.h \
    src/reader/BaseReader.h \
    src/reader/BoneModelReader.h \
    src/reader/ReaderCreator.h \
    src/reader/ReaderCreator.hpp \
    src/reader/ReaderSolution.h \
    src/reader/ReaderSolution.hpp \
    src/reader/SqliteBoneModelReader.h \
    src/reader/TxtBoneModelReader.h \
    src/scene/Scene.h \
    src/square_matrix/SquareMatrix.h \
    src/square_matrix/SquareMatrix.hpp \
    src/square_matrix/SquareMatrixRow.hpp \
    src/transform_strategy/RotateAction.h \
    src/transform_strategy/ScaleAction.h \
    src/transform_strategy/ShiftAction.h \
    src/transform_strategy/TransformAction.h \
    src/transform_strategy/CameraProjectionAction.h \
    src/visitor/Visitor.h \
    src/visitor/DrawVisitor.h \
    src/visitor/TransformVisitor.h \
    src/mainwindow.hpp \
    src/interface.hpp \
    src/facade/SceneFacade.h \
    src/command/draw/BaseDrawCommand.h \
    src/command/draw/DrawSceneQtCommand.h \
    src/command/load/TxtLoadCommandDecorator.h \
    src/command/load/BaseLoadCommand.h \
    src/command/load/MatrixLoadCommand.h \
    src/command/load/ListLoadCommand.h \
    src/command/load/SqliteLoadCommandDecorator.h \
    src/command/load/BaseLoadCommandDecorator.h \
    src/command/camera/SetCameraCommand.h \
    src/command/camera/MoveCameraCommand.h \
    src/command/camera/BaseCameraCommand.h \
    src/command/camera/RemoveCameraCommand.h \
    src/command/camera/AddCameraCommand.h \
    src/command/scene/ClearSceneCommand.h \
    src/command/scene/BaseSceneCommand.h \
    src/command/object/ScaleObjectCommand.h \
    src/command/object/BaseObjectCommand.h \
    src/command/object/ShiftObjectCommand.h \
    src/command/object/RotateObjectCommand.h \
    src/command/object/RemoveObjectCommand.h \
    src/command/object/CompositeObjectCommand.h \
    src/command/BaseCommand.h \
    src/command/scene/GetObjectIDsSceneCommand.h \
    src/command/scene/GetCameraIDsSceneCommand.h \
    src/center/FindCenter.h




SOURCES += ./src/builder/BaseBoneModelBuilder.cpp \
    ./src/builder/ListBoneModelBuilder.cpp \
    ./src/builder/MatrixBoneModeBuilder.cpp \
    ./src/director/BaseBoneModelDirector.cpp \
    ./src/director/BaseDirector.cpp \
    ./src/director/DirectorSolution.cpp \
    ./src/director/ListBoneModelDirector.cpp \
    ./src/director/MatrixBoneModelDirector.cpp \
    ./src/drawer/BaseDrawer.cpp \
    ./src/drawer/QtDrawer.cpp \
    ./src/drawer/BaseDrawerCreator.cpp \
    ./src/drawer/QtDrawerCreator.cpp \
    ./src/exception/baseexception.cpp \
    ./src/manager/LoadManager.cpp \
    ./src/manager/SceneManager.cpp \
    ./src/manager/TransformManager.cpp \
    ./src/objects/BaseModel.cpp \
    ./src/objects/BoneModel.cpp \
    ./src/objects/Camera.cpp \
    ./src/objects/Composite.cpp \
    ./src/objects/Edge.cpp \
    ./src/objects/InvisibleObject.cpp \
    ./src/objects/ListModelStructure.cpp \
    ./src/objects/MatrixModelStructure.cpp \
    ./src/objects/ModelStructure.cpp \
    ./src/objects/Object.cpp \
    ./src/objects/Point.cpp \
    ./src/objects/VisibleObject.cpp \
    ./src/reader/BaseReader.cpp \
    ./src/reader/BoneModelReader.cpp \
    ./src/reader/ReaderSolution.cpp \
    ./src/reader/SqliteBoneModelReader.cpp \
    ./src/reader/TxtBoneModelReader.cpp \
    ./src/scene/Scene.cpp \
    ./src/transform_strategy/RotateAction.cpp \
    ./src/transform_strategy/ScaleAction.cpp \
    ./src/transform_strategy/ShiftAction.cpp \
    ./src/transform_strategy/TransformAction.cpp \
    ./src/transform_strategy/CameraProjectionAction.cpp \
    ./src/visitor/DrawVisitor.cpp \
    ./src/visitor/TransformVisitor.cpp \
    ./src/main.cpp \
    ./src/mainwindow.cpp \
    src/facade/SceneFacade.cpp \
    src/command/BaseCommand.cpp  \
    src/command/camera/SetCameraCommand.cpp  \
    src/command/camera/MoveCameraCommand.cpp  \
    src/command/camera/BaseCameraCommand.cpp  \
    src/command/camera/AddCameraCommand.cpp  \
    src/command/camera/RemoveCameraCommand.cpp  \
    src/command/draw/BaseDrawCommand.cpp  \
    src/command/draw/DrawSceneQtCommand.cpp  \
    src/command/load/MatrixLoadCommand.cpp  \
    src/command/load/SqliteLoadCommandDecorator.cpp  \
    src/command/load/ListLoadCommand.cpp  \
    src/command/load/BaseLoadCommand.cpp  \
    src/command/load/BaseLoadCommandDecorator.cpp  \
    src/command/load/TxtLoadCommandDecorator.cpp  \
    src/command/object/BaseObjectCommand.cpp  \
    src/command/object/RotateObjectCommand.cpp  \
    src/command/object/ShiftObjectCommand.cpp  \
    src/command/object/ScaleObjectCommand.cpp  \
    src/command/object/RemoveObjectCommand.cpp  \
    src/command/object/CompositeObjectCommand.cpp  \
    src/command/scene/ClearSceneCommand.cpp  \
    src/command/scene/BaseSceneCommand.cpp  \
    src/command/scene/GetObjectIDsSceneCommand.cpp  \
    src/command/scene/GetCameraIDsSceneCommand.cpp  \
    src/center/FindCenter.cpp
