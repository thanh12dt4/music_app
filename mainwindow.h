#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMediaPlayer>
#include <QQuickItem>

#include "slist.h"
#include "musiclist.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_browser_clicked();

    void on_pushButton_play_clicked();

    void on_pushButton_previous_clicked();

    void on_pushButton_next_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_horizontalSlider_duration_sliderMoved(int position);

    void on_horizontalSlider_duration_sliderPressed();

    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void updateDurationInfo(qint64 currentInfo);

    void on_pushButton_stop_clicked();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionSlow_triggered();

    void on_actionFast_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    slist* playslist = NULL;
    slist* myslist = NULL;
    QObject* object;
    QMediaPlayer* player;
    qint64 duration;
};

#endif // MAINWINDOW_H
