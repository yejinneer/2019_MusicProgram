#ifndef ADMIN_LOGINWIDGET_H
#define ADMIN_LOGINWIDGET_H

#include <QDialog>
#include <QMessageBox>
#include "User.h"
#include "mainwindow.h"
#include "admin_addmusicwidget.h"
#include "showmusicwidget.h"


namespace Ui {
class admin_loginwidget;
}

class admin_loginwidget : public QDialog
{
    Q_OBJECT

public:
    explicit admin_loginwidget(QWidget *parent = nullptr);
    ~admin_loginwidget();
    User getPick() const;

private slots:
    void on_cancelbtn_clicked();

    void on_loginbtn_clicked();

    void on_idedit_textChanged(const QString &arg1);

    void on_pwedit_textChanged(const QString &arg1);

private:
    Ui::admin_loginwidget *ui;
    User pick;
};

#endif // ADMIN_LOGINWIDGET_H
