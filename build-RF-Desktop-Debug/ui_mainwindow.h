/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *rest;
    QPushButton *pushButton_4;
    QPushButton *salir;
    QTextEdit *bitacora;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 420);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 140, 131, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 180, 131, 27));
        rest = new QPushButton(centralWidget);
        rest->setObjectName(QStringLiteral("rest"));
        rest->setGeometry(QRect(20, 220, 131, 27));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 60, 131, 27));
        salir = new QPushButton(centralWidget);
        salir->setObjectName(QStringLiteral("salir"));
        salir->setGeometry(QRect(20, 340, 131, 27));
        bitacora = new QTextEdit(centralWidget);
        bitacora->setObjectName(QStringLiteral("bitacora"));
        bitacora->setGeometry(QRect(170, 50, 511, 321));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 20, 121, 17));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 300, 131, 27));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 260, 131, 27));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 100, 131, 27));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Agregar Lugar", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Viajar", 0));
        rest->setText(QApplication::translate("MainWindow", "Descansar", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Revisar Bit\303\241cora", 0));
        salir->setText(QApplication::translate("MainWindow", "Salir sin guardar", 0));
        label->setText(QApplication::translate("MainWindow", "Bit\303\241cora de viajes", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Guardar y Salir", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Lugares visitables", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Instrucciones", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
