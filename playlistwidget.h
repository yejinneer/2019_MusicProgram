#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QDialog>
#include <QMessageBox>
#include "ArrayList.h"
#include "playtype.h"

namespace Ui {
class playlistwidget;
}

class playlistwidget : public QDialog
{
    Q_OBJECT

public:
    explicit playlistwidget(ArrayList<Playtype>& p_playList, QWidget *parent = nullptr);
    ~playlistwidget();
    void displayAll();
    ArrayList<Playtype> getList() const;
    ArrayList<Playtype> PlayList;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_ListTable_cellClicked(int row, int column);

private:
    Ui::playlistwidget *ui;


    enum Column{
        DELETE, TITLE, SINGER, ID
    };
};

#endif // PLAYLISTWIDGET_H
