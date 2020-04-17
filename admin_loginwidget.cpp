#include "admin_loginwidget.h"
#include "ui_admin_loginwidget.h"

admin_loginwidget::admin_loginwidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_loginwidget)
{
    ui->setupUi(this);
    ui->idedit->setPlaceholderText("Input ID");
    ui->pwedit->setPlaceholderText("Input PW");
}

admin_loginwidget::~admin_loginwidget()
{
    delete ui;
}

User admin_loginwidget::getPick() const
{
    return pick;
}
void admin_loginwidget::on_cancelbtn_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Do you really want to quit?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        reject();
}

void admin_loginwidget::on_loginbtn_clicked()
{
    User temp;
    temp.setId(pick.getId());
    if (pick.getId().empty() || pick.getPw().empty())
    {
        QMessageBox::information(this,"Error","Input Registration Info!");
    }
    else if (pick.getId() == "yejinn")
    {
        if (pick.getPw() != "yejinn")
            QMessageBox::information(this,"Error","Wrong Password!");
        else{
            done(QDialog::Accepted);
            showmusicwidget showwidget(pick);
            showwidget.exec();
        }
    }
    else
    {
        QMessageBox::information(this,"Error","No ID!");
    }
}

void admin_loginwidget::on_idedit_textChanged(const QString &arg1)
{
    pick.setId(arg1.toStdString());
}

void admin_loginwidget::on_pwedit_textChanged(const QString &arg1)
{
    pick.setPw(arg1.toStdString());
}
