/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *MainFrame;
    QHBoxLayout *Cmd;
    QVBoxLayout *LoadLayout;
    QLabel *LoadLbl;
    QLineEdit *FileNameEntry;
    QLabel *StructureLbl;
    QComboBox *StructureCombo;
    QPushButton *LoadBtn;
    QVBoxLayout *CamerasLayout;
    QLabel *CamerasLbl;
    QHBoxLayout *CameraCoordsLayout;
    QVBoxLayout *CameraXLayout;
    QLabel *CameraXLbl;
    QDoubleSpinBox *CameraXSpin;
    QVBoxLayout *CameraYLayout;
    QLabel *CameraYLbl;
    QDoubleSpinBox *CameraYSpin;
    QVBoxLayout *CameraZLayout;
    QLabel *CameraZLbl;
    QDoubleSpinBox *CameraZSpin;
    QPushButton *AddCameraBtn;
    QVBoxLayout *ObjListLayout;
    QLabel *ObjListLbl;
    QListWidget *ObjList;
    QVBoxLayout *ObjButtonsLayout;
    QPushButton *DelObjBtn;
    QPushButton *CreateCompositeBtn;
    QVBoxLayout *MoveLayout;
    QLabel *MoveX;
    QDoubleSpinBox *MoveXSpin;
    QLabel *MoveY;
    QDoubleSpinBox *MoveYSpin;
    QLabel *MoveZ;
    QDoubleSpinBox *MoveZSpin;
    QPushButton *MoveBtn;
    QVBoxLayout *ScaleLayout;
    QLabel *ScaleX;
    QDoubleSpinBox *ScaleXSpin;
    QLabel *ScaleY;
    QDoubleSpinBox *ScaleYSpin;
    QLabel *ScaleZ;
    QDoubleSpinBox *ScaleZSpin;
    QPushButton *ScaleBtn;
    QVBoxLayout *RotateLayout;
    QLabel *RotateX;
    QDoubleSpinBox *RotateXspin;
    QLabel *RotateY;
    QDoubleSpinBox *RotateYSpin;
    QLabel *RotateZ;
    QDoubleSpinBox *RotateZSpin;
    QPushButton *RotateBtn;
    QGraphicsView *Canvas;
    QPushButton *objectMovePushbutton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1293, 875);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1291, 871));
        MainFrame = new QVBoxLayout(verticalLayoutWidget);
        MainFrame->setObjectName(QString::fromUtf8("MainFrame"));
        MainFrame->setContentsMargins(4, 4, 4, 4);
        Cmd = new QHBoxLayout();
        Cmd->setObjectName(QString::fromUtf8("Cmd"));
        LoadLayout = new QVBoxLayout();
        LoadLayout->setObjectName(QString::fromUtf8("LoadLayout"));
        LoadLbl = new QLabel(verticalLayoutWidget);
        LoadLbl->setObjectName(QString::fromUtf8("LoadLbl"));

        LoadLayout->addWidget(LoadLbl);

        FileNameEntry = new QLineEdit(verticalLayoutWidget);
        FileNameEntry->setObjectName(QString::fromUtf8("FileNameEntry"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FileNameEntry->sizePolicy().hasHeightForWidth());
        FileNameEntry->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(113, 113, 113, 128));
        brush.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        FileNameEntry->setPalette(palette);

        LoadLayout->addWidget(FileNameEntry);

        StructureLbl = new QLabel(verticalLayoutWidget);
        StructureLbl->setObjectName(QString::fromUtf8("StructureLbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(StructureLbl->sizePolicy().hasHeightForWidth());
        StructureLbl->setSizePolicy(sizePolicy1);

        LoadLayout->addWidget(StructureLbl);

        StructureCombo = new QComboBox(verticalLayoutWidget);
        StructureCombo->setObjectName(QString::fromUtf8("StructureCombo"));
        sizePolicy.setHeightForWidth(StructureCombo->sizePolicy().hasHeightForWidth());
        StructureCombo->setSizePolicy(sizePolicy);

        LoadLayout->addWidget(StructureCombo);

        LoadBtn = new QPushButton(verticalLayoutWidget);
        LoadBtn->setObjectName(QString::fromUtf8("LoadBtn"));
        sizePolicy.setHeightForWidth(LoadBtn->sizePolicy().hasHeightForWidth());
        LoadBtn->setSizePolicy(sizePolicy);

        LoadLayout->addWidget(LoadBtn);


        Cmd->addLayout(LoadLayout);

        CamerasLayout = new QVBoxLayout();
        CamerasLayout->setObjectName(QString::fromUtf8("CamerasLayout"));
        CamerasLbl = new QLabel(verticalLayoutWidget);
        CamerasLbl->setObjectName(QString::fromUtf8("CamerasLbl"));

        CamerasLayout->addWidget(CamerasLbl);

        CameraCoordsLayout = new QHBoxLayout();
        CameraCoordsLayout->setObjectName(QString::fromUtf8("CameraCoordsLayout"));
        CameraXLayout = new QVBoxLayout();
        CameraXLayout->setObjectName(QString::fromUtf8("CameraXLayout"));
        CameraXLbl = new QLabel(verticalLayoutWidget);
        CameraXLbl->setObjectName(QString::fromUtf8("CameraXLbl"));

        CameraXLayout->addWidget(CameraXLbl);

        CameraXSpin = new QDoubleSpinBox(verticalLayoutWidget);
        CameraXSpin->setObjectName(QString::fromUtf8("CameraXSpin"));

        CameraXLayout->addWidget(CameraXSpin);


        CameraCoordsLayout->addLayout(CameraXLayout);

        CameraYLayout = new QVBoxLayout();
        CameraYLayout->setObjectName(QString::fromUtf8("CameraYLayout"));
        CameraYLbl = new QLabel(verticalLayoutWidget);
        CameraYLbl->setObjectName(QString::fromUtf8("CameraYLbl"));

        CameraYLayout->addWidget(CameraYLbl);

        CameraYSpin = new QDoubleSpinBox(verticalLayoutWidget);
        CameraYSpin->setObjectName(QString::fromUtf8("CameraYSpin"));

        CameraYLayout->addWidget(CameraYSpin);


        CameraCoordsLayout->addLayout(CameraYLayout);

        CameraZLayout = new QVBoxLayout();
        CameraZLayout->setObjectName(QString::fromUtf8("CameraZLayout"));
        CameraZLbl = new QLabel(verticalLayoutWidget);
        CameraZLbl->setObjectName(QString::fromUtf8("CameraZLbl"));

        CameraZLayout->addWidget(CameraZLbl);

        CameraZSpin = new QDoubleSpinBox(verticalLayoutWidget);
        CameraZSpin->setObjectName(QString::fromUtf8("CameraZSpin"));

        CameraZLayout->addWidget(CameraZSpin);


        CameraCoordsLayout->addLayout(CameraZLayout);


        CamerasLayout->addLayout(CameraCoordsLayout);

        AddCameraBtn = new QPushButton(verticalLayoutWidget);
        AddCameraBtn->setObjectName(QString::fromUtf8("AddCameraBtn"));

        CamerasLayout->addWidget(AddCameraBtn);


        Cmd->addLayout(CamerasLayout);

        ObjListLayout = new QVBoxLayout();
        ObjListLayout->setObjectName(QString::fromUtf8("ObjListLayout"));
        ObjListLbl = new QLabel(verticalLayoutWidget);
        ObjListLbl->setObjectName(QString::fromUtf8("ObjListLbl"));

        ObjListLayout->addWidget(ObjListLbl);

        ObjList = new QListWidget(verticalLayoutWidget);
        ObjList->setObjectName(QString::fromUtf8("ObjList"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ObjList->sizePolicy().hasHeightForWidth());
        ObjList->setSizePolicy(sizePolicy2);
        ObjList->setResizeMode(QListView::Fixed);

        ObjListLayout->addWidget(ObjList);


        Cmd->addLayout(ObjListLayout);

        ObjButtonsLayout = new QVBoxLayout();
        ObjButtonsLayout->setObjectName(QString::fromUtf8("ObjButtonsLayout"));
        ObjButtonsLayout->setSizeConstraint(QLayout::SetFixedSize);
        DelObjBtn = new QPushButton(verticalLayoutWidget);
        DelObjBtn->setObjectName(QString::fromUtf8("DelObjBtn"));
        sizePolicy.setHeightForWidth(DelObjBtn->sizePolicy().hasHeightForWidth());
        DelObjBtn->setSizePolicy(sizePolicy);

        ObjButtonsLayout->addWidget(DelObjBtn);

        CreateCompositeBtn = new QPushButton(verticalLayoutWidget);
        CreateCompositeBtn->setObjectName(QString::fromUtf8("CreateCompositeBtn"));
        sizePolicy.setHeightForWidth(CreateCompositeBtn->sizePolicy().hasHeightForWidth());
        CreateCompositeBtn->setSizePolicy(sizePolicy);

        ObjButtonsLayout->addWidget(CreateCompositeBtn);


        Cmd->addLayout(ObjButtonsLayout);

        MoveLayout = new QVBoxLayout();
        MoveLayout->setObjectName(QString::fromUtf8("MoveLayout"));
        MoveX = new QLabel(verticalLayoutWidget);
        MoveX->setObjectName(QString::fromUtf8("MoveX"));

        MoveLayout->addWidget(MoveX);

        MoveXSpin = new QDoubleSpinBox(verticalLayoutWidget);
        MoveXSpin->setObjectName(QString::fromUtf8("MoveXSpin"));
        MoveXSpin->setMinimum(-500.000000000000000);
        MoveXSpin->setMaximum(500.000000000000000);

        MoveLayout->addWidget(MoveXSpin);

        MoveY = new QLabel(verticalLayoutWidget);
        MoveY->setObjectName(QString::fromUtf8("MoveY"));

        MoveLayout->addWidget(MoveY);

        MoveYSpin = new QDoubleSpinBox(verticalLayoutWidget);
        MoveYSpin->setObjectName(QString::fromUtf8("MoveYSpin"));
        MoveYSpin->setMinimum(-500.000000000000000);
        MoveYSpin->setMaximum(500.000000000000000);

        MoveLayout->addWidget(MoveYSpin);

        MoveZ = new QLabel(verticalLayoutWidget);
        MoveZ->setObjectName(QString::fromUtf8("MoveZ"));

        MoveLayout->addWidget(MoveZ);

        MoveZSpin = new QDoubleSpinBox(verticalLayoutWidget);
        MoveZSpin->setObjectName(QString::fromUtf8("MoveZSpin"));
        MoveZSpin->setMinimum(-500.000000000000000);
        MoveZSpin->setMaximum(500.000000000000000);

        MoveLayout->addWidget(MoveZSpin);

        MoveBtn = new QPushButton(verticalLayoutWidget);
        MoveBtn->setObjectName(QString::fromUtf8("MoveBtn"));

        MoveLayout->addWidget(MoveBtn);


        Cmd->addLayout(MoveLayout);

        ScaleLayout = new QVBoxLayout();
        ScaleLayout->setObjectName(QString::fromUtf8("ScaleLayout"));
        ScaleX = new QLabel(verticalLayoutWidget);
        ScaleX->setObjectName(QString::fromUtf8("ScaleX"));

        ScaleLayout->addWidget(ScaleX);

        ScaleXSpin = new QDoubleSpinBox(verticalLayoutWidget);
        ScaleXSpin->setObjectName(QString::fromUtf8("ScaleXSpin"));
        ScaleXSpin->setMinimum(-500.000000000000000);
        ScaleXSpin->setMaximum(500.000000000000000);

        ScaleLayout->addWidget(ScaleXSpin);

        ScaleY = new QLabel(verticalLayoutWidget);
        ScaleY->setObjectName(QString::fromUtf8("ScaleY"));

        ScaleLayout->addWidget(ScaleY);

        ScaleYSpin = new QDoubleSpinBox(verticalLayoutWidget);
        ScaleYSpin->setObjectName(QString::fromUtf8("ScaleYSpin"));
        ScaleYSpin->setMinimum(-500.000000000000000);
        ScaleYSpin->setMaximum(500.000000000000000);

        ScaleLayout->addWidget(ScaleYSpin);

        ScaleZ = new QLabel(verticalLayoutWidget);
        ScaleZ->setObjectName(QString::fromUtf8("ScaleZ"));

        ScaleLayout->addWidget(ScaleZ);

        ScaleZSpin = new QDoubleSpinBox(verticalLayoutWidget);
        ScaleZSpin->setObjectName(QString::fromUtf8("ScaleZSpin"));
        ScaleZSpin->setMinimum(-500.000000000000000);
        ScaleZSpin->setMaximum(500.000000000000000);

        ScaleLayout->addWidget(ScaleZSpin);

        ScaleBtn = new QPushButton(verticalLayoutWidget);
        ScaleBtn->setObjectName(QString::fromUtf8("ScaleBtn"));

        ScaleLayout->addWidget(ScaleBtn);


        Cmd->addLayout(ScaleLayout);

        RotateLayout = new QVBoxLayout();
        RotateLayout->setObjectName(QString::fromUtf8("RotateLayout"));
        RotateX = new QLabel(verticalLayoutWidget);
        RotateX->setObjectName(QString::fromUtf8("RotateX"));

        RotateLayout->addWidget(RotateX);

        RotateXspin = new QDoubleSpinBox(verticalLayoutWidget);
        RotateXspin->setObjectName(QString::fromUtf8("RotateXspin"));
        RotateXspin->setMinimum(-500.000000000000000);
        RotateXspin->setMaximum(500.000000000000000);

        RotateLayout->addWidget(RotateXspin);

        RotateY = new QLabel(verticalLayoutWidget);
        RotateY->setObjectName(QString::fromUtf8("RotateY"));

        RotateLayout->addWidget(RotateY);

        RotateYSpin = new QDoubleSpinBox(verticalLayoutWidget);
        RotateYSpin->setObjectName(QString::fromUtf8("RotateYSpin"));
        RotateYSpin->setMinimum(-500.000000000000000);
        RotateYSpin->setMaximum(500.000000000000000);

        RotateLayout->addWidget(RotateYSpin);

        RotateZ = new QLabel(verticalLayoutWidget);
        RotateZ->setObjectName(QString::fromUtf8("RotateZ"));

        RotateLayout->addWidget(RotateZ);

        RotateZSpin = new QDoubleSpinBox(verticalLayoutWidget);
        RotateZSpin->setObjectName(QString::fromUtf8("RotateZSpin"));
        RotateZSpin->setMinimum(-500.000000000000000);
        RotateZSpin->setMaximum(500.000000000000000);

        RotateLayout->addWidget(RotateZSpin);

        RotateBtn = new QPushButton(verticalLayoutWidget);
        RotateBtn->setObjectName(QString::fromUtf8("RotateBtn"));

        RotateLayout->addWidget(RotateBtn);


        Cmd->addLayout(RotateLayout);


        MainFrame->addLayout(Cmd);

        Canvas = new QGraphicsView(verticalLayoutWidget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));

        MainFrame->addWidget(Canvas);

        objectMovePushbutton = new QPushButton(centralwidget);
        objectMovePushbutton->setObjectName(QString::fromUtf8("objectMovePushbutton"));
        objectMovePushbutton->setGeometry(QRect(1260, 970, 161, 27));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        LoadLbl->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260", nullptr));
        FileNameEntry->setInputMask(QString());
        FileNameEntry->setText(QString());
        FileNameEntry->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 (.txt/.stl)", nullptr));
        StructureLbl->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        LoadBtn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        CamerasLbl->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\321\213", nullptr));
        CameraXLbl->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        CameraYLbl->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        CameraZLbl->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        AddCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        ObjListLbl->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        DelObjBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\265", nullptr));
        CreateCompositeBtn->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\262 \320\272\320\276\320\274\320\277\320\276\320\267\320\270\321\202", nullptr));
        MoveX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        MoveY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        MoveZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        MoveBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        ScaleX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        ScaleY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        ScaleZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        ScaleBtn->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        RotateX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        RotateY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        RotateZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        RotateBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        objectMovePushbutton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
