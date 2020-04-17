#ifndef ADMIN_ADDSINGERWIDGET_H
#define ADMIN_ADDSINGERWIDGET_H

#include <QDialog>
#include "SingerType.h"
#include "showmusicwidget.h"

namespace Ui {
class admin_addsingerwidget;
}

class admin_addsingerwidget : public QDialog
{
    Q_OBJECT

public:
    explicit admin_addsingerwidget(QWidget *parent = nullptr);
    ~admin_addsingerwidget();

private slots:
    void on_idEdit_textChanged(const QString &arg1);

    void on_nameEdit_textChanged(const QString &arg1);

    void on_teamCombo_currentTextChanged(const QString &arg1);

    void on_genderCombo_currentTextChanged(const QString &arg1);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_cancelbtn_clicked();

    void on_okbtn_2_clicked();

private:
    Ui::admin_addsingerwidget *ui;
    string id;
    string name;
    string team;
    string gender;
    string debut;
    SingerType nowsinger;

};

#endif // ADMIN_ADDSINGERWIDGET_H
