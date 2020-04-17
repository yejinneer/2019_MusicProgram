#include "admin_addmusicwidget.h"
#include "ui_admin_addmusicwidget.h"
extern showmusicwidget *Main;

admin_addmusicwidget::admin_addmusicwidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_addmusicwidget)
{
    QIntValidator *intValidator=new QIntValidator(0,9999);
    ui->setupUi(this);
    ui->idEdit->setValidator(intValidator);
    ui->idEdit->setPlaceholderText(QString("Integer"));
    ui->nameEdit->setPlaceholderText(QString("String"));
    ui->singerEdit->setPlaceholderText(QString("String"));
    ui->composerEdit->setPlaceholderText(QString("String"));
}

admin_addmusicwidget::~admin_addmusicwidget()
{
    delete ui;
}

void admin_addmusicwidget::on_idEdit_textChanged(const QString &arg1)
{
    Id = arg1.toStdString();
}

void admin_addmusicwidget::on_nameEdit_textChanged(const QString &arg1)
{
    one.SetName(arg1.toStdString());
}

void admin_addmusicwidget::on_composerEdit_textChanged(const QString &arg1)
{
    one.SetComposer(arg1.toStdString());
}

void admin_addmusicwidget::on_singerEdit_textChanged(const QString &arg1)
{
    one.SetSinger(arg1.toStdString());
}

void admin_addmusicwidget::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    one.SetGenre(arg1.toStdString());
}

void admin_addmusicwidget::on_comboBox_currentTextChanged(const QString &arg1)
{
    one.SetTag(arg1.toStdString());
}

void admin_addmusicwidget::on_okbtn_clicked()
{
    if (Id.empty() || one.GetName().empty() ||one.GetSinger().empty() || one.GetComposer().empty() || one.GetGenre().empty() || one.GetTag().empty())
        QMessageBox::information(this,"Error!","Insert right Info.");
    else
    {
        QMessageBox MsgBox;
        MsgBox.setText("Input completed?");
        MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
        MsgBox.setDefaultButton(QMessageBox::Ok);
        if ( MsgBox.exec() == QMessageBox::Ok )
        {
            one.SetID(atoi(Id.c_str()));
            SingerType nowsinger;
            nowsinger.SetsName(one.GetSinger());

            if(Main->getSinger(nowsinger) == false){
                QMessageBox::information(this,"Error!","No Singer in SingerList, Add Singer!");
                }
            else{
                int pandan = Main->musicAdd(one);
                if (pandan == 1){
                    Song insong(one.GetID(), one.GetName(), one.GetTag());
                    nowsinger.AddSong(insong);
                    QMessageBox::information(this,"ADD","Add Succeeded!");
                    this->close();
                    }
                else if (pandan == 0)
                    QMessageBox::information(this,"Error!","Same Id Exists");
                else if (pandan == -1)
                    QMessageBox::information(this,"Error!","Full List");
                }
        }
    }
}

void admin_addmusicwidget::on_cancelbtn_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Do you really want to quit?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        reject();
}

