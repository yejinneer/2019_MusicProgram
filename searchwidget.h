#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QDialog>
#include "SortedList.h"
#include "itemtype.h"

namespace Ui {
class searchwidget;
}

class searchwidget : public QDialog
{
    Q_OBJECT

public:
    explicit searchwidget(const SortedList<ItemType> s_musiclist, QWidget *parent = nullptr);
    ~searchwidget();

private slots:

    void on_titleEdit_textChanged(const QString &arg1);

    int on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    SortedList<ItemType> MusicList;
    ItemType item;
    string searchtext;
    Ui::searchwidget *ui;
};

#endif // SEARCHWIDGET_H
