#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "slist.h"
#include "dialog.h"
#include "music.h"
#include "musiclist.h"

#include <QDebug>
#include <QFileDialog>
#include <QStringList>
#include <QString>
#include <iostream>
#include <QQuickItem>
#include <QGenericArgument>
#include <QMediaPlayer>
#include <QTime>

int open_newlist = 0;

void deleteItem (void* item){
    delete (MusicList*) item;
}

bool isSameItem (void* src, void* dst) {
    return !strcmp (((MusicList*)src)->getPath(), ((MusicList*)dst)->getPath());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl::fromLocalFile("animation.qml"));
    ui->quickWidget->show();
    object = ui->quickWidget->rootObject();
    player = new QMediaPlayer;
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT (positionChanged(qint64)));
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
    ui->horizontalSlider_duration->setRange(0, player->duration());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete object;
}

void MainWindow::on_pushButton_browser_clicked()
{
    QStringList pathfiles = QFileDialog::getOpenFileNames(this, tr("Open File"), QDir::currentPath(), "*.mp3" );
    if(pathfiles.size() > 0){
        open_newlist = 1;
        on_pushButton_stop_clicked();
        myslist = slist_delete_all_x(myslist, deleteItem);
        for (int i = 0; i < pathfiles.size(); ++i) {
            QFileInfo fileInfo(pathfiles[i]);
            QListWidgetItem *item = new MusicList(fileInfo.fileName(), fileInfo.fileName().toStdString().c_str(), fileInfo.filePath().toStdString().c_str());
            ui->listWidget->addItem(item);
            myslist = slist_append(myslist, (void*)item);
            ui->lineEdit->setText(fileInfo.path().toStdString().c_str());
        }
     }
}

void MainWindow::on_pushButton_play_clicked()
{
    if(open_newlist == 1) {
        if (myslist){
            playslist = myslist;
            on_listWidget_itemClicked((QListWidgetItem*)myslist->data);
            ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(://Icon/pause.png);}");
            ui->pushButton_play->setStyleSheet("QPushButton:hover { background-color: rgb(180, 180, 180);}");
            ui->listWidget->setCurrentItem((QListWidgetItem*)myslist->data);
            open_newlist = 0;
        }
    }
    else {
        if (playslist){
            if (player->state() == QMediaPlayer::PausedState || player->state() == QMediaPlayer::StoppedState){
                player->play();
                ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(://Icon/pause.png);}");
                ui->pushButton_play->setStyleSheet("QPushButton:hover { background-color: rgb(180, 180, 180);}");
            }
            else if(player->state() == QMediaPlayer::PlayingState) {
                player->pause();
                ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(://Icon/play.png);}");
                ui->pushButton_play->setStyleSheet("QPushButton:hover { background-color: rgb(180, 180, 180);}");
            }
        }
    }

}

void MainWindow::on_pushButton_previous_clicked()
{
    if (playslist) {
        if (playslist->previous) {
            QString picpath;
            playslist = playslist->previous;
            if (playslist->previous) {
                ID3_Tag itemtag;
                itemtag.Link(((MusicList*)playslist->previous->data)->getPath(), ID3TT_ALL);
                picpath = QString (((MusicList*)playslist->previous->data)->getName()) + ".jpg";
                ((MusicList*)playslist->previous->data)->setTag(itemtag, picpath.toStdString().c_str());
                qDebug () << picpath;
            }
            QObject *t_object = object->findChild<QObject*> ("page");
            if (t_object) {
                QMetaObject::invokeMethod(t_object, "pageprevious", Q_ARG (QString, picpath));
            }
            QString filepath = QString(((MusicList*)playslist->data)->getPath());
            player->setMedia(QUrl::fromLocalFile(filepath));
            player->play();
            ui->listWidget->setCurrentItem((QListWidgetItem*)playslist->data);
            ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(://Icon/pause.png);}");
            ui->pushButton_play->setStyleSheet("QPushButton:hover { background-color: rgb(180, 180, 180);}");
        }
    }
}

void MainWindow::on_pushButton_next_clicked()
{
    if (playslist) {
        if (playslist->next) {
            QString picpath;
            playslist = playslist->next;
            if (playslist->next) {
                ID3_Tag itemtag;
                itemtag.Link(((MusicList*)playslist->next->data)->getPath(), ID3TT_ALL);
                picpath = QString (((MusicList*)playslist->next->data)->getName()) + ".jpg";
                ((MusicList*)playslist->next->data)->setTag(itemtag, picpath.toStdString().c_str());
                qDebug () << picpath;
            }
            QObject *t_object = object->findChild<QObject*> ("page");
            if (t_object) {
                QMetaObject::invokeMethod(t_object, "pagenext", Q_ARG (QString, picpath));
            }
            QString filepath = QString(((MusicList*)playslist->data)->getPath());
            player->setMedia(QUrl::fromLocalFile(filepath));
            player->play();
            ui->listWidget->setCurrentItem((QListWidgetItem*)playslist->data);
            ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(://Icon/pause.png);}");
            ui->pushButton_play->setStyleSheet("QPushButton:hover { background-color: rgb(180, 180, 180);}");
        }
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString listpic[3];
    MusicList* castitem = dynamic_cast <MusicList*> (item);
    playslist = slist_find (myslist, castitem, isSameItem);
    ID3_Tag itemtag;
    itemtag.Link(((MusicList*)playslist->data)->getPath(), ID3TT_ALL);
    QString picpath = QString (((MusicList*)playslist->data)->getName()) + ".jpg";
    ((MusicList*)playslist->data)->setTag(itemtag, picpath.toStdString().c_str());
    listpic[1] = QString (((MusicList*)playslist->data)->getTag()->picpath);
    if (playslist->next) {
        ID3_Tag itemtag;
        itemtag.Link(((MusicList*)playslist->next->data)->getPath(), ID3TT_ALL);
        QString picpath = QString (((MusicList*)playslist->next->data)->getName()) + ".jpg";
        ((MusicList*)playslist->next->data)->setTag(itemtag, picpath.toStdString().c_str());
        listpic[2] = QString(((MusicList*)playslist->next->data)->getTag()->picpath);
    }
    if (playslist->previous) {
        ID3_Tag itemtag;
        itemtag.Link(((MusicList*)playslist->previous->data)->getPath(), ID3TT_ALL);
        QString picpath = QString (((MusicList*)playslist->previous->data)->getName()) + ".jpg";
        ((MusicList*)playslist->previous->data)->setTag(itemtag, picpath.toStdString().c_str());
        listpic[0] = QString(((MusicList*)playslist->previous->data)->getTag()->picpath);
    }
    QObject *t_object = object->findChild<QObject*> ("page");
    if (t_object) {
        QMetaObject::invokeMethod(t_object, "showit", Q_ARG(QString, listpic[0] ), Q_ARG(QString, listpic[1] ), Q_ARG(QString, listpic[2] ));
    }
    QString filepath = QString(((MusicList*)playslist->data)->getPath());
    player->setMedia(QUrl::fromLocalFile(filepath));
    player->play();
}

void MainWindow::on_horizontalSlider_duration_sliderMoved(int position)
{
     player->setPosition(position * 1000);
}

void MainWindow::durationChanged(qint64 duration)
{
    this->duration = duration/1000;
    ui->horizontalSlider_duration->setMaximum(duration / 1000);
}

void MainWindow::positionChanged(qint64 position){
    if (!ui->horizontalSlider_duration->isSliderDown()) {
        ui->horizontalSlider_duration->setValue(position/1000);
    }
    updateDurationInfo (position / 1000);
}
void MainWindow::updateDurationInfo(qint64 currentInfo)
{
    QString cStr, tStr;
    if (currentInfo || duration) {
        QTime currentTime((currentInfo/3600)%60, (currentInfo/60)%60, currentInfo%60, (currentInfo*1000)%1000);
        QTime totalTime((duration/3600)%60, (duration/60)%60, duration%60, (duration*1000)%1000);
        QString format = "mm:ss";
        if (duration > 3600)
            format = "hh:mm:ss";
        cStr = currentTime.toString(format);
        tStr = totalTime.toString(format);
    }
    ui->label_duration->setText(cStr);
    ui->label_total->setText(tStr);
}
void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if (status == QMediaPlayer::EndOfMedia) {
        on_pushButton_next_clicked();
    }
}

void MainWindow::on_horizontalSlider_duration_sliderPressed()
{
    //player->setPosition(position * 1000);
}

void MainWindow::on_pushButton_stop_clicked()
{
    player->stop();
    ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(://Icon/play.png);}");
    ui->pushButton_play->setStyleSheet("QPushButton:hover { background-color: rgb(180, 180, 180);}");
}

void MainWindow::on_actionOpen_triggered()
{
    on_pushButton_browser_clicked();
}

void MainWindow::on_actionExit_triggered()
{
   QApplication::quit();
}

void MainWindow::on_actionSlow_triggered()
{
    QObject *page = object->findChild<QObject*>("page");
    if (page)
        page->setProperty("time", 2000);
}

void MainWindow::on_actionFast_triggered()
{
    QObject *page = object->findChild<QObject*>("page");
    if (page)
        page->setProperty("time", 1000);

}

void MainWindow::on_actionAbout_triggered()
{
    Dialog myDialog;
    myDialog.exec();

}
