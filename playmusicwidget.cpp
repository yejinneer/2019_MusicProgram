#include "playmusicwidget.h"
#include "ui_playmusicwidget.h"

playmusicwidget::playmusicwidget(const ItemType& item, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playmusicwidget)
{
    ui->setupUi(this);
    tempitem = item;
    ui->name->setText(QString::fromStdString(tempitem.GetName()));
    ui->singer->setText(QString::fromStdString(tempitem.GetSinger()));
    ui->composer->setText(QString::fromStdString(tempitem.GetComposer()));
}

playmusicwidget::~playmusicwidget()
{
    delete ui;
}

void playmusicwidget::on_pushButton_clicked()
{
    close();
}
