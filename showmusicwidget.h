#ifndef SHOWMUSICWIDGET_H
#define SHOWMUSICWIDGET_H
#pragma once

#include <QDialog>
#include <QString>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QSignalMapper>
#include <QCheckBox>
#include <string>
#include <QAction>
#include <QMessageBox>
#include <QHBoxLayout>

#include "admin_addmusicwidget.h"
#include "admin_addsingerwidget.h"
#include "playmusicwidget.h"
#include "playlistwidget.h"
#include "searchwidget.h"
#include "recommend_by_tag.h"

#include "SortedList.h"
#include "ArrayList.h"
#include "CircularDoubleLinked.h"

#include "itemtype.h"
#include "User.h"
#include "SingerType.h"
#include "playtype.h"

namespace Ui {
 class showmusicwidget;
}

class showmusicwidget : public QDialog
{
    Q_OBJECT

public:
    explicit showmusicwidget(User, QWidget *parent = nullptr);
    ~showmusicwidget();
    void displayAll(const SortedList<ItemType>&);
    int musicAdd(ItemType inmusic);
    int singerAdd(SingerType insinger);
    int playAdd(Playtype inplay);
    bool getSinger(SingerType& one);
    bool getSong(ItemType& one);

//    void adminaccept();
//    void adminsavefile();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_ListTable_cellClicked(int row, int column);

    void on_pushButton_4_clicked();

    void on_search_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::showmusicwidget *ui;
    SortedList<ItemType> m_displayList;
    SortedList<ItemType> m_musicList;
    CircularDoubleLinkedList<SingerType> s_singerList;
    ArrayList<Playtype> m_playList;

    User nowmember;

    enum Column
    {
       PLAY ,DELETE, ID ,TITLE, COMPOSER, SINGER, GENRE, TAG
    };
};

#endif // SHOWMUSICWIDGET_H
