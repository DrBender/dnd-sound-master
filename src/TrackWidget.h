#pragma once
#ifndef TRACK_WIDGET_H
#define TRACK_WIDGET_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class TrackWidget : public QWidget
{
    Q_OBJECT
public:
    TrackWidget(QWidget *parent);
    ~TrackWidget();

protected:
    QLineEdit *name;
    QLineEdit *url;
    QPushButton *deleteBtn;
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QPushButton *stopBtn;
};

#endif /*TRACK_WIDGET_H*/
