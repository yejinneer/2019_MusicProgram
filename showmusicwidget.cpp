#include "showmusicwidget.h"
#include "ui_showmusicwidget.h"
showmusicwidget *Main;
showmusicwidget::showmusicwidget(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showmusicwidget)
{
    Main = this;
    ui->setupUi(this);
    nowmember = user;

    ui->ListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ListTable->setRowCount(0);
    ui->ListTable->setColumnWidth(PLAY, 40);
    ui->ListTable->setColumnWidth(DELETE, 50);
    ui->ListTable->setColumnWidth(ID, 40);
    ui->ListTable->setColumnWidth(TITLE, 100);
    ui->ListTable->setColumnWidth(COMPOSER, 100);
    ui->ListTable->setColumnWidth(SINGER, 100);
    ui->ListTable->setColumnWidth(GENRE, 70);
    ui->ListTable->setColumnWidth(TAG, 70);

    displayAll(m_musicList);
}

showmusicwidget::~showmusicwidget()
{
    delete ui;


}

void showmusicwidget::displayAll(const SortedList<ItemType> &givenlist){
    m_displayList = givenlist;
    ui->ListTable->setRowCount(0);
    if (m_displayList.IsEmpty())
    {
        ui->ListTable->setRowCount(1);
        ui->ListTable->setItem(0,0, new QTableWidgetItem(QString::fromStdString(" ▶")));
        ui->ListTable->setItem(0,1, new QTableWidgetItem(QString::fromStdString(" -")));
        ui->ListTable->setItem(0,3, new QTableWidgetItem(QString::fromStdString("Empty")));
    }
    else
    {
        m_displayList.ResetList();
        ItemType temp;
        while(m_displayList.GetNextItem(temp)!=-1)
        {

            ui->ListTable->insertRow(ui->ListTable->rowCount());
            int index = ui->ListTable->rowCount()-1;

            //table show
            QTableWidgetItem* play = new QTableWidgetItem(QString::fromStdString(" ▶"));
            QTableWidgetItem* del = new QTableWidgetItem(QString::fromStdString(" ∨"));
            QTableWidgetItem* id = new QTableWidgetItem(QString::number(temp.GetID()));
            QTableWidgetItem* title = new QTableWidgetItem(QString::fromStdString(temp.GetName()));
            QTableWidgetItem* singer = new QTableWidgetItem(QString::fromStdString(temp.GetSinger()));
            QTableWidgetItem* composer = new QTableWidgetItem(QString::fromStdString(temp.GetComposer()));
            QTableWidgetItem* genre = new QTableWidgetItem(QString::fromStdString(temp.GetGenre()));
            QTableWidgetItem* tag = new QTableWidgetItem(QString::fromStdString(temp.GetTag()));

            play->setTextAlignment(Qt::AlignCenter);
            del->setTextAlignment(Qt::AlignCenter);
            id->setTextAlignment(Qt::AlignCenter);
            title->setTextAlignment(Qt::AlignCenter);
            composer->setTextAlignment(Qt::AlignCenter);
            singer->setTextAlignment(Qt::AlignCenter);
            genre->setTextAlignment(Qt::AlignCenter);
            tag->setTextAlignment(Qt::AlignCenter);

            ui->ListTable->setItem(index, PLAY, play);
            ui->ListTable->setItem(index, DELETE, del);
            ui->ListTable->setItem(index, ID, id);
            ui->ListTable->setItem(index, TITLE, title);
            ui->ListTable->setItem(index, COMPOSER, composer);
            ui->ListTable->setItem(index, SINGER, singer);
            ui->ListTable->setItem(index, GENRE, genre);
            ui->ListTable->setItem(index, TAG, tag);
        }
    }
}

int showmusicwidget::musicAdd(ItemType inmusic){
    return m_musicList.Add(inmusic);
}

int showmusicwidget::singerAdd(SingerType insinger){
    return s_singerList.Add(insinger);
}

int showmusicwidget::playAdd(Playtype inplay){
    return m_playList.Add(inplay);
}

bool showmusicwidget::getSong(ItemType &one){
    return m_musicList.Retrieve_Binary(one);
}

bool showmusicwidget::getSinger(SingerType &one){
    SingerType tempsinger;
    s_singerList.ResetList();
    for(int i  = 0; i < s_singerList.GetLength(); i++){
        s_singerList.GetNextItem(tempsinger);
        if(tempsinger.GetName() == one.GetName())
            return 1;
    }
    return 0;
}

void showmusicwidget::on_pushButton_clicked()
{
    if(nowmember.getId() == "yejinn"){
        admin_addmusicwidget addwidget;
        addwidget.setModal(true);
        addwidget.exec();
        displayAll(m_musicList);
    }
    else{
        QMessageBox::information(this,"Error!","You are not ADMIN !");
    }
}

void showmusicwidget::on_pushButton_2_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Do you really want to quit?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Ok )
        this->close();
}

void showmusicwidget::on_pushButton_3_clicked()
{
    QMessageBox MsgBox;
    MsgBox.setText("Delete All?");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);
    if ( MsgBox.exec() == QMessageBox::Cancel )
        return;
    m_musicList.MakeEmpty();
    displayAll(m_musicList);
}

//void showmusicwidget::adminaccept(){
//    string m_filename = "cd /Users/ye/Desktop/yejinn_musiclist.txt";
//    string s_filename = "cd /Users/ye/Desktop/yejinn_singerlist.txt";
//    ifstream m_Infile(m_filename);
//    ifstream s_Infile(s_filename);

//    if(m_Infile.is_open()){
//        ItemType tempMusic;
//        tempMusic.ReadDataFromFile(m_Infile);
//        while(!m_Infile.eof())
//        {
//            m_musicList.Add(tempMusic);
//            Song tempSong(tempMusic.GetID(), tempMusic.GetName(), tempMusic.GetTag());
//            SingerType tempSinger;
//            tempSinger.SetsName(tempMusic.GetSinger());
//            s_singerList.Retrieve(tempSinger);
//            tempSinger.AddSong(tempSong);

//            tempMusic.ReadDataFromFile(m_Infile);
//        }
//        m_Infile.close();
//    }

//    if(s_Infile.is_open()){
//        SingerType tempSinger;
//        tempSinger.ReadDataFromFile(s_Infile);
//        while(!s_Infile.eof()){
//            s_singerList.Add(tempSinger);
//            tempSinger.ReadDataFromFile(s_Infile);
//        }
//        s_Infile.close();
//    }
//}

//void showmusicwidget::adminsavefile(){
//    if(nowmember.getId() == "yejinn"){
//        string m_filename = "cd /Users/ye/Desktop/yejinn_musiclist.txt";
//        ofstream m_Outfile(m_filename);
//        m_musicList.ResetList();
//        ItemType tempMusic;
//        while (m_musicList.GetNextItem(tempMusic)!=-1)
//        {
//            tempMusic.WriteDataToFile(m_Outfile);
//        }

//        string s_filename = "cd /Users/ye/Desktop/yejinn_singerlist.txt";
//        ofstream s_Outfile(s_filename);
//        s_singerList.ResetList();
//        SingerType tempsinger;
//        for (int i = 0; i < s_singerList.GetLength(); i++)
//        {
//           s_singerList.GetNextItem(tempsinger);
//           tempsinger.WriteDataToFile(s_Outfile);
//        }
//        s_Outfile.close();
//        m_Outfile.close();
//        QMessageBox::information(this,"Save","Admin Save Completed!");
//    }

//    else{
//        QMessageBox::information(this,"ERROR","You are not ADMIN!");
//    }
//}

void showmusicwidget::on_pushButton_5_clicked()
{
    if(nowmember.getId() == "yejinn"){
        admin_addsingerwidget addwidget;
        addwidget.setModal(true);
        addwidget.exec();
    }
    else{
        QMessageBox::information(this,"Error!","You are not ADMIN !");
    }
}


void showmusicwidget::on_ListTable_cellClicked(int row, int column)
{
    if(column == PLAY){
        ItemType itemtemp;
        itemtemp = m_displayList.at(row);
        Playtype playtemp;
        playtemp.setId(itemtemp.GetID());
        playtemp.setSinger(itemtemp.GetSinger());
        playtemp.setName(itemtemp.GetName());

        m_playList.Add(playtemp);
        playmusicwidget musicwidget(itemtemp);
        musicwidget.exec();
    }
    if(column == DELETE){
        ItemType itemtemp;
        itemtemp = m_displayList.at(row);
        m_musicList.Delete(itemtemp);
        displayAll(m_musicList);
    }
    else
        return;
}

void showmusicwidget::on_pushButton_4_clicked()
{
    playlistwidget playwidget(m_playList);
    playwidget.exec();
}



void showmusicwidget::on_search_clicked()
{
    searchwidget searchwid(m_musicList);
    searchwid.exec();
}

void showmusicwidget::on_pushButton_6_clicked()
{
    recommend_by_tag recommendwidget(m_musicList);
    recommendwidget.exec();
}

void showmusicwidget::on_pushButton_7_clicked()
{
    close();
}
