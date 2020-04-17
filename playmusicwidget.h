#ifndef PLAYMUSICWIDGET_H
#define PLAYMUSICWIDGET_H

#include <QDialog>

#include "itemtype.h"

namespace Ui {
class playmusicwidget;
}

class playmusicwidget : public QDialog
{
    Q_OBJECT

public:
    explicit playmusicwidget(const ItemType& item, QWidget *parent = nullptr);
    ~playmusicwidget();


private slots:
    void on_pushButton_clicked();

private:
    ItemType tempitem;
    Ui::playmusicwidget *ui;

};

#endif // PLAYMUSICWIDGET_H
