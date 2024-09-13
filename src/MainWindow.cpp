#include "MainWindow.h"
#include "TrackWidget.h"
#include <QDebug>
#include <QVBoxLayout>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qscrollarea.h>
#include <QWidget>
#include <QFile>

MainWindow::MainWindow()
{
    qDebug() << "MainWindow::MainWindow()";
    QWidget * cent = new QWidget(this);
    setCentralWidget(cent);
    buttonPanel = new QWidget(this);


    QFile styleF;
    styleF.setFileName(":/style");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();
    setStyleSheet(qssStr);
    /*menu;*/
    scrollArea = new QScrollArea(this);
    scrollWidget = new QWidget(scrollArea);
    scrollWidget->setLayout(new QVBoxLayout(scrollWidget));
    /*scrollWidget->()*/
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);
    
    addBtn = new QPushButton(this);
    saveBtn = new QPushButton(this);
    openBtn = new QPushButton(this);
    pauseAllBtn = new QPushButton(this);
    downloadBtn = new QPushButton(this);
    /*QVector<TrackWidget> tracks;*/
    QWidget * btnsPanel = new QWidget(this);
    btnsPanel->setLayout(new QHBoxLayout(btnsPanel));
    btnsPanel->layout()->addWidget(addBtn);
    btnsPanel->layout()->addWidget(saveBtn);
    btnsPanel->layout()->addWidget(openBtn);
    btnsPanel->layout()->addWidget(pauseAllBtn);
    btnsPanel->layout()->addWidget(downloadBtn);
    centralWidget()->setLayout(new QVBoxLayout());


    centralWidget()->layout()->addWidget(btnsPanel);
    centralWidget()->layout()->addWidget(scrollArea);

    setTexts();
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addTrack);
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow::~MainWindow()";
}

void MainWindow::setTexts()
{
    addBtn->setText("Add");
    saveBtn->setText("Save");
    openBtn->setText("Open");
    pauseAllBtn->setText("Pause All");
    downloadBtn->setText("Download");
}

void MainWindow::addTrack()
{
    qDebug() << "addTrack";
    TrackWidget * t = new TrackWidget(scrollWidget);
    tracks.append(t);
    scrollWidget->layout()->addWidget(t);
}
