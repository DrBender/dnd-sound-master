#pragma once
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qvector.h>
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "TrackWidget.h"
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QVector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    void setTexts();
public slots:
    void addTrack();

protected:
    QWidget *buttonPanel;
    QMenuBar *menu;
    QScrollArea *scrollArea;
    QWidget * scrollWidget;

    QPushButton *addBtn;
    QPushButton *saveBtn;
    QPushButton *openBtn;
    QPushButton *pauseAllBtn;
    QPushButton *downloadBtn;
    QVector<TrackWidget*> tracks;
};

#endif /* MAIN_WINDOW_H */
