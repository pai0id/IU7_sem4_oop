#include "mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <cmath>

#include "src/command/load/MatrixLoadCommand.h"
#include "src/command/load/ListLoadCommand.h"
#include "src/command/load/SqliteLoadCommandDecorator.h"
#include "src/command/load/TxtLoadCommandDecorator.h"
#include "src/command/draw/DrawSceneQtCommand.h"
#include "src/command/scene/GetCameraIDsSceneCommand.h"
#include "src/command/scene/GetObjectIDsSceneCommand.h"
#include "src/command/camera/AddCameraCommand.h"
#include "src/command/camera/SetCameraCommand.h"
#include "src/command/camera/RemoveCameraCommand.h"
#include "src/command/object/ShiftObjectCommand.h"
#include "src/command/object/RotateObjectCommand.h"
#include "src/command/object/ScaleObjectCommand.h"
#include "src/command/object/CompositeObjectCommand.h"
#include "src/command/object/RemoveObjectCommand.h"
#include "src/scene/Point.hpp"
#include "src/exception/baseexception.hpp"

#include <iostream>

double DegToRad(double angle) { return angle / 180.0 * M_PI; }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Canvas->setScene(new QGraphicsScene);
    ui->Canvas->setBackgroundBrush(Qt::white);
    connectButtons();
    ui->StructureCombo->addItem("Список", 0);
    ui->StructureCombo->addItem("Матрица", 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectButtons() {
    connect(ui->LoadBtn, &QPushButton::clicked, this, &MainWindow::on_loadButtonclicked);
    connect(ui->AddCameraBtn, &QPushButton::clicked, this, &MainWindow::on_cameraAddPushbuttonclicked);
    connect(ui->SetCameraBtn, &QPushButton::clicked, this, &MainWindow::on_cameraSetPushbuttonclicked);
    connect(ui->MoveBtn, &QPushButton::clicked, this, &MainWindow::on_objectMovePushbuttonclicked);
    connect(ui->RotateBtn, &QPushButton::clicked, this, &MainWindow::on_objectRotatePushbuttonclicked);
    connect(ui->ScaleBtn, &QPushButton::clicked, this, &MainWindow::on_objectScalePushbuttonclicked);
    connect(ui->DelObjBtn, &QPushButton::clicked, this, &MainWindow::on_objectDeletePushbuttonclicked);
    connect(ui->CreateCompositeBtn, &QPushButton::clicked, this, &MainWindow::on_objectCompositePushbuttonclicked);
}

bool endsWith(const std::string &str, const std::string &suffix) {
    if (str.length() >= suffix.length()) {
        return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
    } else {
        return false;
    }
}

void MainWindow::on_loadButtonclicked() {
//    std::string str = ui->FileNameEntry->text().toStdString();
    std::string str = "/home/andrey05/Documents/labs_oop/lab_03_qt/data/cube.txt";
    const char* fname = str.c_str();

    std::shared_ptr<BaseLoadCommand> command;

    if (ui->StructureCombo->currentText() == "Список")
        command = std::make_shared<ListLoadCommand>();
    else
        command = std::make_shared<MatrixLoadCommand>();

    std::shared_ptr<BaseCommand> decorator;
    if (endsWith(fname, ".sqlite"))
        decorator = std::make_shared<SqliteLoadCommandDecorator>(*command, fname);
    else
        decorator = std::make_shared<TxtLoadCommandDecorator>(*command, fname);
    try {
        _facade.execute(*decorator);
    } catch (BaseException &exc) {
        QMessageBox::critical(nullptr, "Ошибка", exc.what());
        return;
    }

    drawScene();
    updateObjectList();
}

void MainWindow::on_cameraAddPushbuttonclicked() {
    double x = ui->CameraXSpin->value();
    double y = ui->CameraYSpin->value();
    double z = ui->CameraZSpin->value();
    Point pos(x, y, z);
    AddCameraCommand command(pos);
    _facade.execute(command);
    updateCameraList();
    updateObjectList();
}

void MainWindow::on_cameraSetPushbuttonclicked() {
    auto cams = getSelectedCameraIds();
    if (cams.size() != 1) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать ровно одну камеру.");
        return;
    }
    SetCameraCommand command(cams[0]);
    _facade.execute(command);
    drawScene();
}

void MainWindow::updateCameraList() {
    ui->CamerasList->clear();
    GetCameraIDsSceneCommand ids;
    _facade.execute(ids);
    std::vector<size_t> cameraIds = ids.GetIDs();
    for (size_t id : cameraIds) {
        ui->CamerasList->addItem(QString::number(id));
    }
}
void MainWindow::updateObjectList() {
    ui->ObjList->clear();
    GetObjectIDsSceneCommand ids;
    _facade.execute(ids);
    std::vector<size_t> objectIds = ids.GetIDs();
    for (size_t id : objectIds) {
        ui->ObjList->addItem(QString::number(id));
    }
}
std::vector<size_t> MainWindow::getSelectedObjectIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->ObjList->count(); i++) {
        if (ui->ObjList->item(i)->isSelected()) {
            ids.push_back(ui->ObjList->item(i)->text().toInt());
        }
    }
    return ids;
}
std::vector<size_t> MainWindow::getSelectedCameraIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->CamerasList->count(); i++) {
        if (ui->CamerasList->item(i)->isSelected()) {
            ids.push_back(ui->CamerasList->item(i)->text().toInt());
        }
    }
    return ids;
}

void MainWindow::drawScene() {
    ui->Canvas->scene()->clear();
    ui->Canvas->scene()->setSceneRect(ui->Canvas->sceneRect());
    DrawSceneQtCommand drawcommand(ui->Canvas->scene());
    _facade.execute(drawcommand);
}

void MainWindow::on_objectMovePushbuttonclicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->MoveXSpin->value();
    double y = ui->MoveYSpin->value();
    double z = ui->MoveZSpin->value();
    for (auto &id : objs) {
        ShiftObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

void MainWindow::on_objectRotatePushbuttonclicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = DegToRad(ui->RotateXspin->value());
    double y = DegToRad(ui->RotateYSpin->value());
    double z = DegToRad(ui->RotateZSpin->value());
    for (auto &id : objs) {
        RotateObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}


void MainWindow::on_objectScalePushbuttonclicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->ScaleXSpin->value();
    double y = ui->ScaleYSpin->value();
    double z = ui->ScaleZSpin->value();
    for (auto &id : objs) {
        ScaleObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

void MainWindow::on_objectDeletePushbuttonclicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    for (auto &id : objs) {
        RemoveObjectCommand command(id);
        _facade.execute(command);
    }

    drawScene();
    updateCameraList();
    updateObjectList();
}

void MainWindow::on_objectCompositePushbuttonclicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    CompositeObjectCommand command(objs);
    _facade.execute(command);

    drawScene();
    updateCameraList();
    updateObjectList();
}
