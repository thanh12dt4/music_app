/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtQuickWidgets/QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionSlow;
    QAction *actionFast;
    QAction *actionAbout;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPATH;
    QLineEdit *lineEdit;
    QPushButton *pushButton_browser;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QQuickWidget *quickWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_duration;
    QSlider *horizontalSlider_duration;
    QLabel *label_total;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_previous;
    QPushButton *pushButton_play;
    QPushButton *pushButton_next;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(647, 330);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(700, 330));
        MainWindow->setAcceptDrops(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 194, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionSlow = new QAction(MainWindow);
        actionSlow->setObjectName(QStringLiteral("actionSlow"));
        actionFast = new QAction(MainWindow);
        actionFast->setObjectName(QStringLiteral("actionFast"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 21, 591, 245));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelPATH = new QLabel(layoutWidget);
        labelPATH->setObjectName(QStringLiteral("labelPATH"));

        horizontalLayout_3->addWidget(labelPATH);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_browser = new QPushButton(layoutWidget);
        pushButton_browser->setObjectName(QStringLiteral("pushButton_browser"));

        horizontalLayout_3->addWidget(pushButton_browser);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        quickWidget = new QQuickWidget(layoutWidget);
        quickWidget->setObjectName(QStringLiteral("quickWidget"));
        quickWidget->setMaximumSize(QSize(400, 200));
        quickWidget->setStyleSheet(QStringLiteral(""));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        verticalLayout->addWidget(quickWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_duration = new QLabel(layoutWidget);
        label_duration->setObjectName(QStringLiteral("label_duration"));

        horizontalLayout_2->addWidget(label_duration);

        horizontalSlider_duration = new QSlider(layoutWidget);
        horizontalSlider_duration->setObjectName(QStringLiteral("horizontalSlider_duration"));
        horizontalSlider_duration->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_duration);

        label_total = new QLabel(layoutWidget);
        label_total->setObjectName(QStringLiteral("label_total"));

        horizontalLayout_2->addWidget(label_total);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_stop = new QPushButton(layoutWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setMinimumSize(QSize(50, 50));
        pushButton_stop->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(180, 180, 180); }"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icon/stop.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_stop->setIcon(icon2);
        pushButton_stop->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_stop);

        pushButton_previous = new QPushButton(layoutWidget);
        pushButton_previous->setObjectName(QStringLiteral("pushButton_previous"));
        pushButton_previous->setMinimumSize(QSize(50, 50));
        pushButton_previous->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(180, 180, 180); }"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icon/previous.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_previous->setIcon(icon3);
        pushButton_previous->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButton_previous);

        pushButton_play = new QPushButton(layoutWidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        pushButton_play->setMinimumSize(QSize(50, 50));
        pushButton_play->setAcceptDrops(false);
        pushButton_play->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(180, 180, 180); }"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icon/play.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_play->setIcon(icon4);
        pushButton_play->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_play);

        pushButton_next = new QPushButton(layoutWidget);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        pushButton_next->setMinimumSize(QSize(50, 50));
        pushButton_next->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(180, 180, 180); }"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icon/next.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_next->setIcon(icon5);
        pushButton_next->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButton_next);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(17, 208, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(listWidget);


        verticalLayout_2->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(pushButton_browser, horizontalSlider_duration);
        QWidget::setTabOrder(horizontalSlider_duration, quickWidget);
        QWidget::setTabOrder(quickWidget, lineEdit);
        QWidget::setTabOrder(lineEdit, listWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);
        menuView->addAction(actionSlow);
        menuView->addAction(actionFast);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionSlow->setText(QApplication::translate("MainWindow", "Slow", Q_NULLPTR));
        actionFast->setText(QApplication::translate("MainWindow", "Fast", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        labelPATH->setText(QApplication::translate("MainWindow", "PATH", Q_NULLPTR));
        pushButton_browser->setText(QApplication::translate("MainWindow", "Browser", Q_NULLPTR));
        label_duration->setText(QApplication::translate("MainWindow", "_:_", Q_NULLPTR));
        label_total->setText(QApplication::translate("MainWindow", "_:_", Q_NULLPTR));
        pushButton_stop->setText(QString());
        pushButton_previous->setText(QString());
        pushButton_play->setText(QString());
        pushButton_next->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
