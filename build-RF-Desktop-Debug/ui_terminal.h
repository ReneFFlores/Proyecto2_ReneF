/********************************************************************************
** Form generated from reading UI file 'terminal.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINAL_H
#define UI_TERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Terminal
{
public:

    void setupUi(QDialog *Terminal)
    {
        if (Terminal->objectName().isEmpty())
            Terminal->setObjectName(QStringLiteral("Terminal"));
        Terminal->resize(700, 400);

        retranslateUi(Terminal);

        QMetaObject::connectSlotsByName(Terminal);
    } // setupUi

    void retranslateUi(QDialog *Terminal)
    {
        Terminal->setWindowTitle(QApplication::translate("Terminal", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Terminal: public Ui_Terminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINAL_H
