#pragma once
#include <qpushbutton.h>
#include <qvector.h>
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QVector>
#include "TrackWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

protected:
    QWidget *buttonPanel;
    QMenuBar *menu;
    QScrollArea *scrollArea;

    QPushButton * addBtn;
    QPushButton * saveBtn;
    QPushButton * openBtn;
    QPushButton * pauseAllBtn;
    QPushButton * downloadBtn;
    QVector<TrackWidget> tracks;
};

#endif /* MAIN_WINDOW_H */
