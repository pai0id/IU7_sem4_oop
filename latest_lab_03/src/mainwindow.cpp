#include "mainwindow.hpp"

#include <QPushButton>
#include <QMessageBox>
#include <cmath>

#include "MatrixLoadCommand.h"
#include "ListLoadCommand.h"
#include "SqliteLoadCommandDecorator.h"
#include "TxtLoadCommandDecorator.h"
#include "DrawSceneQtCommand.h"
#include "GetCameraIDsSceneCommand.h"
#include "GetObjectIDsSceneCommand.h"
#include "AddCameraCommand.h"
#include "SetCameraCommand.h"
#include "RemoveCameraCommand.h"
#include "MoveCameraCommand.h"
#include "ShiftObjectCommand.h"
#include "RotateObjectCommand.h"
#include "ScaleObjectCommand.h"
#include "CompositeObjectCommand.h"
#include "RemoveObjectCommand.h"
#include "Point.h"
#include "baseexception.h"

double DegToRad(double angle) { return angle / 180.0 * M_PI; }


MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->Canvas->setScene(new QGraphicsScene);
    ui->Canvas->scene()->setSceneRect(ui->Canvas->sceneRect());
    ui->Canvas->setBackgroundBrush(Qt::white);
    connectButtons();
    ui->StructureCombo->addItem("Список", 0);
    ui->StructureCombo->addItem("Матрица", 1);
    ui->ObjList->setSelectionMode(QAbstractItemView::MultiSelection);
}

MyMainWindow::~MyMainWindow() {
    delete ui;
}

void MyMainWindow::connectButtons() {
    connect(ui->LoadBtn, &QPushButton::clicked, this, &MyMainWindow::on_loadButton_clicked);
    connect(ui->AddCameraBtn, &QPushButton::clicked, this, &MyMainWindow::on_cameraAddPushbutton_clicked);
    connect(ui->SetCameraBtn, &QPushButton::clicked, this, &MyMainWindow::on_cameraSetPushbutton_clicked);
    connect(ui->MoveBtn, &QPushButton::clicked, this, &MyMainWindow::on_objectMovePushbutton_clicked);
    connect(ui->RotateBtn, &QPushButton::clicked, this, &MyMainWindow::on_objectRotatePushbutton_clicked);
    connect(ui->ScaleBtn, &QPushButton::clicked, this, &MyMainWindow::on_objectScalePushbutton_clicked);
    connect(ui->DelObjBtn, &QPushButton::clicked, this, &MyMainWindow::on_objectDeletePushbutton_clicked);
    connect(ui->CreateCompositeBtn, &QPushButton::clicked, this, &MyMainWindow::on_objectCompositePushbutton_clicked);
}

bool endsWith(const std::string &str, const std::string &suffix) {
    if (str.length() >= suffix.length()) {
        return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
    } else {
        return false;
    }
}

void MyMainWindow::on_loadButton_clicked() {
    std::string fname = ui->FileNameEntry->text().toStdString();
    
    std::shared_ptr<BaseLoadCommand> command;

    if (ui->StructureCombo->currentText() == "Список")
        command = std::make_shared<ListLoadCommand>();
    else
        command = std::make_shared<MatrixLoadCommand>();
    
    std::shared_ptr<BaseCommand> decorator;
    if (endsWith(fname, ".sqlite") || endsWith(fname, ".sqlite3"))
        decorator = std::make_shared<SqliteLoadCommandDecorator>(*command, fname);
    else
        decorator = std::make_shared<TxtLoadCommandDecorator>(*command, fname);
    try {
        _facade.Execute(*decorator);
    } catch (BaseException &exc) {
        QMessageBox::critical(nullptr, "Ошибка", exc.what());
        return;
    }
    
    drawScene();
    updateObjectList();
}

void MyMainWindow::on_cameraAddPushbutton_clicked() {
    double x = ui->CameraXSpin->value();
    double y = ui->CameraYSpin->value();
    double z = ui->CameraZSpin->value();
    Point pos(x, y, z);
    AddCameraCommand command(pos);
    _facade.Execute(command);
    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_cameraSetPushbutton_clicked() {
    auto cams = getSelectedCameraIds();
    if (cams.size() != 1) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать ровно одну камеру.");
        return;
    }   
    SetCameraCommand command(cams[0]);
    _facade.Execute(command);
    drawScene();
}

void MyMainWindow::updateCameraList() {
    ui->CamerasList->clear();
    GetCameraIDsSceneCommand ids;
    _facade.Execute(ids);
    std::vector<size_t> cameraIds = ids.GetIDs();
    for (size_t id : cameraIds) {
        ui->CamerasList->addItem(QString::number(id));
    }
}
void MyMainWindow::updateObjectList() {
    ui->ObjList->clear();
    GetObjectIDsSceneCommand ids;
    _facade.Execute(ids);
    std::vector<size_t> objectIds = ids.GetIDs();
    for (size_t id : objectIds) {
        ui->ObjList->addItem(QString::number(id));
    }
}
std::vector<size_t> MyMainWindow::getSelectedObjectIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->ObjList->count(); i++) {
        if (ui->ObjList->item(i)->isSelected()) {
            ids.push_back(ui->ObjList->item(i)->text().toInt());
        }
    }
    return ids;
}
std::vector<size_t> MyMainWindow::getSelectedCameraIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->CamerasList->count(); i++) {
        if (ui->CamerasList->item(i)->isSelected()) {
            ids.push_back(ui->CamerasList->item(i)->text().toInt());
        }
    }
    return ids;
}

void MyMainWindow::drawScene() {
    ui->Canvas->scene()->clear();
    ui->Canvas->scene()->setSceneRect(ui->Canvas->sceneRect());
    DrawSceneQtCommand drawcommand(ui->Canvas->scene());
    _facade.Execute(drawcommand);
}

void MyMainWindow::on_objectMovePushbutton_clicked() {
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
        _facade.Execute(command);
    }

    drawScene();
}

void MyMainWindow::on_objectRotatePushbutton_clicked() { 
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
        _facade.Execute(command);
    }

    drawScene();
}


void MyMainWindow::on_objectScalePushbutton_clicked() {
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
        _facade.Execute(command);
    }

    drawScene();
}

void MyMainWindow::on_objectDeletePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    for (auto &id : objs) {
        RemoveCameraCommand command1(id);
        _facade.Execute(command1);
        RemoveObjectCommand command2(id);
        _facade.Execute(command2);
    }

    drawScene();
    updateObjectList();
    updateCameraList();
}

void MyMainWindow::on_objectCompositePushbutton_clicked() { 
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    CompositeObjectCommand command(objs);
    _facade.Execute(command);

    drawScene();
    updateObjectList();
    updateCameraList();
}
