#include "playlistwidget.h"
#include "ui_playlistwidget.h"

playlistwidget::playlistwidget(ArrayList<Playtype>& p_playList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playlistwidget)
{
    PlayList = p_playList;
    ui->setupUi(this);
    ui->ListTable->setRowCount(0);
    ui->ListTable->setColumnWidth(DELETE, 50);
    ui->ListTable->setColumnWidth(TITLE, 100);
    ui->ListTable->setColumnWidth(SINGER, 100);
    ui->ListTable->setColumnWidth(ID, 40);

    displayAll();
}

playlistwidget::~playlistwidget()
{
    delete ui;
}

void playlistwidget::displayAll(){
    ui->ListTable->setRowCount(0);

    if(PlayList.isEmpty()){
        ui->ListTable->setRowCount(0);
        ui->ListTable->setItem(0,0,new QTableWidgetItem("-"));
        ui->ListTable->setItem(0,1,new QTableWidgetItem("-"));
        ui->ListTable->setItem(0,2,new QTableWidgetItem("-"));
    }

    else{
        PlayList.ResetList();
        Playtype temp;
        for(int i = 0; i < PlayList.GetLength(); i++){
            PlayList.GetNextItem(temp);
            ui->ListTable->insertRow(ui->ListTable->rowCount());
            int index = ui->ListTable->rowCount()-1;

            //table show
            QTableWidgetItem* del = new QTableWidgetItem(QString::fromStdString(" ∨"));
            QTableWidgetItem* id = new QTableWidgetItem(QString::number(temp.getId()));
            QTableWidgetItem* title = new QTableWidgetItem(QString::fromStdString(temp.getName()));
            QTableWidgetItem* singer = new QTableWidgetItem(QString::fromStdString(temp.getSinger()));

            id->setTextAlignment(Qt::AlignCenter);
            del->setTextAlignment(Qt::AlignCenter);
            title->setTextAlignment(Qt::AlignCenter);
            singer->setTextAlignment(Qt::AlignCenter);

            ui->ListTable->setItem(index, DELETE, del);
            ui->ListTable->setItem(index, TITLE, title);
            ui->ListTable->setItem(index, ID, id);
            ui->ListTable->setItem(index, SINGER, singer);
        }
    }
}

void playlistwidget::on_pushButton_2_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Delete All?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Cancel )
        return;
    PlayList.MakeEmpty();
    displayAll();
}

void playlistwidget::on_pushButton_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Back to Music List");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        this->close();
}

ArrayList<Playtype> playlistwidget::getList() const{
    return PlayList;
}

void playlistwidget::on_ListTable_cellClicked(int row, int column)
{
    if(column == DELETE){
        QMessageBox MsgBox;
        MsgBox.setText("Delete Music ?");
        MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
        MsgBox.setDefaultButton(QMessageBox::Ok);
        if ( MsgBox.exec() == QMessageBox::Cancel )
            return;

        Playtype tempplay;
        tempplay = PlayList.at(row);
        PlayList.Delete(tempplay);
        displayAll();
    }
}
