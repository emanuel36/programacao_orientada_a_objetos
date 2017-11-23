#include "metro.h"
#include "ui_metro.h"

Metro::Metro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Metro)
{
    ui->setupUi(this);
}

Metro::~Metro()
{
    delete ui;
}
