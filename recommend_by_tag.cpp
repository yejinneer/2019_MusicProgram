#include "recommend_by_tag.h"
#include "ui_recommend_by_tag.h"

recommend_by_tag::recommend_by_tag(SortedList<ItemType> inlist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recommend_by_tag)
{
    tempMusicList = inlist;
    ui->setupUi(this);
    ui->ListTable->setRowCount(0);
    ui->ListTable->setColumnWidth(TITLE, 100);
    ui->ListTable->setColumnWidth(SINGER, 100);
    ui->ListTable->setColumnWidth(COMPOSER, 100);
}

recommend_by_tag::~recommend_by_tag()
{
    delete ui;
}

void recommend_by_tag::on_comboBox_currentTextChanged(const QString &arg1)
{
    tagchosen = arg1.toStdString();
}

void recommend_by_tag::choosetag(SortedList<ItemType> inlist){
    ItemType temp;
    inlist.ResetList();
    while(inlist.GetNextItem(temp) != -1){
        if(temp.GetTag() == tagchosen){
            MusicList.Add(temp);
        }
    }
}

void recommend_by_tag::displayAll(){
    ui->ListTable->setRowCount(0);

    if(MusicList.IsEmpty()){
        ui->ListTable->setRowCount(0);
        ui->ListTable->setItem(0,0,new QTableWidgetItem("-"));
        ui->ListTable->setItem(0,1,new QTableWidgetItem("-"));
        ui->ListTable->setItem(0,2,new QTableWidgetItem("-"));
    }

    else{
        MusicList.ResetList();
        ItemType temp;
        while(MusicList.GetNextItem(temp) != -1){
            ui->ListTable->insertRow(ui->ListTable->rowCount());
            int index = ui->ListTable->rowCount()-1;

            //table show
            QTableWidgetItem* title = new QTableWidgetItem(QString::fromStdString(temp.GetName()));
            QTableWidgetItem* singer = new QTableWidgetItem(QString::fromStdString(temp.GetSinger()));
            QTableWidgetItem* composer = new QTableWidgetItem(QString::fromStdString(temp.GetComposer()));

            composer->setTextAlignment(Qt::AlignCenter);
            title->setTextAlignment(Qt::AlignCenter);
            singer->setTextAlignment(Qt::AlignCenter);

            ui->ListTable->setItem(index, TITLE, title);
            ui->ListTable->setItem(index, SINGER, singer);
            ui->ListTable->setItem(index, COMPOSER, composer);
        }
    }
}

void recommend_by_tag::on_pushButton_2_clicked()
{
    MusicList.MakeEmpty();
    choosetag(tempMusicList);
    displayAll();
}

void recommend_by_tag::on_pushButton_clicked()
{
    close();
}
