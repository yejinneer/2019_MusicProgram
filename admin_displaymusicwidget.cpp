#include "admin_displaymusicwidget.h"
#include "ui_admin_displaymusicwidget.h"

admin_displaymusicwidget::admin_displaymusicwidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_displaymusicwidget)
{
    ui->setupUi(this);
}

admin_displaymusicwidget::~admin_displaymusicwidget()
{
    delete ui;
}
