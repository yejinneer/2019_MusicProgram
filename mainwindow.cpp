#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setmusictexts(){
    srand(time(NULL));
    randomInt = rand()%4 + 1;
    if(randomInt == 1){
        musictexts = "Music is the universal language";
    }
    if(randomInt == 2){
        musictexts = "Music is speech of angels";
    }
    if(randomInt == 3){
        musictexts = "Music washes away the dust of everyday life";
    }
    if(randomInt == 4){
        musictexts = "Music is the wine that fills the cup of silence";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    admin_loginwidget adminlogin;
    adminlogin.exec();
}


void MainWindow::on_pushButton_clicked()
{
    setmusictexts();
    ui->randomtext->setText(QString::fromStdString(musictexts));
}
