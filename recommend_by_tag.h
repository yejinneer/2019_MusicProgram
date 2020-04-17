#ifndef RECOMMEND_BY_TAG_H
#define RECOMMEND_BY_TAG_H

#include <QDialog>
#include "itemtype.h"
#include "SortedList.h"

namespace Ui {
class recommend_by_tag;
}

class recommend_by_tag : public QDialog
{
    Q_OBJECT

public:
    explicit recommend_by_tag(SortedList<ItemType> inlist, QWidget *parent = nullptr);
    ~recommend_by_tag();
    SortedList<ItemType> MusicList;
    SortedList<ItemType> tempMusicList;
    void choosetag(SortedList<ItemType> inlist);
    void displayAll();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::recommend_by_tag *ui;
    ItemType item;
    string tagchosen;

    enum Column{
        TITLE, SINGER, COMPOSER
    };
};

#endif // RECOMMEND_BY_TAG_H
