#include "terminal.h"
#include "ui_terminal.h"

Terminal::Terminal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Terminal)
{
    ui->setupUi(this);
}

Terminal::~Terminal()
{
    delete ui;
}
