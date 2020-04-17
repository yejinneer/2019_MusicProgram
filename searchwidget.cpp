#include "searchwidget.h"
#include "ui_searchwidget.h"

searchwidget::searchwidget(const SortedList<ItemType> s_musicList,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchwidget)
{
    MusicList = s_musicList;
    ui->setupUi(this);
}

searchwidget::~searchwidget()
{
    delete ui;
}

void searchwidget::on_titleEdit_textChanged(const QString &arg1)
{
    searchtext = arg1.toStdString();
}

int searchwidget::on_pushButton_clicked()
{
    ItemType tempitem;
    MusicList.ResetList();
    while(MusicList.GetNextItem(tempitem) != -1){
        if(tempitem.GetName().find(searchtext) != std::string::npos){
            item = tempitem;
            ui->id->setText(QString::number(tempitem.GetID()));
            ui->title->setText(QString::fromStdString(tempitem.GetName()));
            ui->composer->setText(QString::fromStdString(tempitem.GetComposer()));
            ui->singer->setText(QString::fromStdString(tempitem.GetSinger()));
            ui->genre->setText(QString::fromStdString(tempitem.GetGenre()));
            ui->tag->setText(QString::fromStdString(tempitem.GetTag()));
            return 1;
        }
    }
    ui->id->setText(QString::fromStdString("Not Found"));
    ui->title->setText(QString::fromStdString("Not Found"));
    ui->composer->setText(QString::fromStdString("Not Found"));
    ui->singer->setText(QString::fromStdString("Not Found"));
    ui->genre->setText(QString::fromStdString("Not Found"));
    ui->tag->setText(QString::fromStdString("Not Found"));
    return 0;
}

void searchwidget::on_pushButton_2_clicked()
{
    close();
}
