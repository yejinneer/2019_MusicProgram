#include "admin_addsingerwidget.h"
#include "ui_admin_addsingerwidget.h"
extern showmusicwidget *Main;

admin_addsingerwidget::admin_addsingerwidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_addsingerwidget)
{
    ui->setupUi(this);
    ui->idEdit->setPlaceholderText(QString("Integer"));
    ui->nameEdit->setPlaceholderText(QString("String"));
}

admin_addsingerwidget::~admin_addsingerwidget()
{
    delete ui;
}

void admin_addsingerwidget::on_idEdit_textChanged(const QString &arg1)
{
    id = arg1.toStdString();
}

void admin_addsingerwidget::on_nameEdit_textChanged(const QString &arg1)
{
    nowsinger.SetsName(arg1.toStdString());
}

void admin_addsingerwidget::on_teamCombo_currentTextChanged(const QString &arg1)
{
    nowsinger.SetsGroup(arg1.toStdString());
}

void admin_addsingerwidget::on_genderCombo_currentTextChanged(const QString &arg1)
{
    nowsinger.SetsGender(arg1.toStdString());
}

void admin_addsingerwidget::on_dateEdit_userDateChanged(const QDate &date)
{
    QString debut = date.toString("yyyy.MM.dd");
    nowsinger.SetsDebut(debut.toStdString());
}

void admin_addsingerwidget::on_cancelbtn_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Do you really want to quit?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        reject();
}

void admin_addsingerwidget::on_okbtn_2_clicked()
{
    if(nowsinger.GetName().empty() ||nowsinger.GetsDebut().empty()||nowsinger.GetsGroup().empty()||nowsinger.GetsGender().empty())
        QMessageBox::information(this,"Error!","Insert right Info.");
    else{
        nowsinger.SetsId(atoi(id.c_str()));
        int pandan = Main->singerAdd(nowsinger);
        if(pandan == 1){
            QMessageBox::information(this,"ADD","Add Succeed!");
            this->close();
        }
        else if (pandan == 0)
            QMessageBox::information(this,"Error!","Same Singer Exists");
        else if (pandan == -1)
            QMessageBox::information(this,"Error!","List is Full");
    }
}
