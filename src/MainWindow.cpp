#include "MainWindow.h"
#include <QDebug>
#include <QVBoxLayout>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qscrollarea.h>
#include <qwidget.h>

MainWindow::MainWindow()
{
    qDebug() << "MainWindow::MainWindow()";
    QWidget * cent = new QWidget(this);
    setCentralWidget(cent);
    buttonPanel = new QWidget(this);
    /*menu;*/
    scrollArea = new QScrollArea(this);

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

}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow::~MainWindow()";
}
