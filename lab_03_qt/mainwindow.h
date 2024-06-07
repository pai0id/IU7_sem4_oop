#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "src/Facade.hpp"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void connectButtons();
    Ui::MainWindow *ui;
    Facade _facade;

private slots:
    void on_loadButtonclicked();
    void on_cameraAddPushbuttonclicked();
    void on_cameraSetPushbuttonclicked();
    void on_objectMovePushbuttonclicked();
    void on_objectRotatePushbuttonclicked();
    void on_objectScalePushbuttonclicked();
    void on_objectDeletePushbuttonclicked();
    void on_objectCompositePushbuttonclicked();

private:
    void drawScene();
    void updateCameraList();
    void updateObjectList();
    std::vector<size_t> getSelectedObjectIds();
    std::vector<size_t> getSelectedCameraIds();
};
#endif // MAINWINDOW_H
