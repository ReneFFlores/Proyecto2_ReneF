/********************************************************************************
** Form generated from reading UI file 'addplace.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLACE_H
#define UI_ADDPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_addplace
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *city;
    QLineEdit *country;

    void setupUi(QDialog *addplace)
    {
        if (addplace->objectName().isEmpty())
            addplace->setObjectName(QStringLiteral("addplace"));
        addplace->resize(400, 300);
        buttonBox = new QDialogButtonBox(addplace);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(addplace);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 80, 67, 17));
        label_2 = new QLabel(addplace);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 120, 67, 17));
        city = new QLineEdit(addplace);
        city->setObjectName(QStringLiteral("city"));
        city->setGeometry(QRect(140, 80, 211, 27));
        country = new QLineEdit(addplace);
        country->setObjectName(QStringLiteral("country"));
        country->setGeometry(QRect(140, 120, 211, 27));

        retranslateUi(addplace);
        QObject::connect(buttonBox, SIGNAL(accepted()), addplace, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addplace, SLOT(reject()));

        QMetaObject::connectSlotsByName(addplace);
    } // setupUi

    void retranslateUi(QDialog *addplace)
    {
        addplace->setWindowTitle(QApplication::translate("addplace", "Dialog", 0));
        label->setText(QApplication::translate("addplace", "Ciudad:", 0));
        label_2->setText(QApplication::translate("addplace", "Pais:", 0));
    } // retranslateUi

};

namespace Ui {
    class addplace: public Ui_addplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLACE_H
