#ifndef ADDPLACE_H
#define ADDPLACE_H

#include <QDialog>

namespace Ui {
class addplace;
}

class addplace : public QDialog
{
    Q_OBJECT

public:
    explicit addplace(QWidget *parent = 0);
    ~addplace();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addplace *ui;
};

#endif // ADDPLACE_H
