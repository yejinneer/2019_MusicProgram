#ifndef ADMIN_ADDMUSICWIDGET_H
#define ADMIN_ADDMUSICWIDGET_H

#include <QDialog>
#include <QMessageBox>
#include "SortedList.h"
#include "itemtype.h"
#include "showmusicwidget.h"

namespace Ui {
class admin_addmusicwidget;
}

class admin_addmusicwidget : public QDialog
{
    Q_OBJECT

public:
    explicit admin_addmusicwidget(QWidget *parent = nullptr);
    ~admin_addmusicwidget();
    ItemType getnewItem() const;

private slots:
    void on_idEdit_textChanged(const QString &arg1);

    void on_nameEdit_textChanged(const QString &arg1);

    void on_composerEdit_textChanged(const QString &arg1);

    void on_singerEdit_textChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_okbtn_clicked();

    void on_cancelbtn_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::admin_addmusicwidget *ui;
    string Id;
    string Type;
    string Lyrics;

    ItemType one;
};

#endif // ADMIN_ADDMUSICWIDGET_H
