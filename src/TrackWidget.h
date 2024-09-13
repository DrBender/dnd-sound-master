#pragma once
#ifndef TRACK_WIDGET_H
#define TRACK_WIDGET_H

#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QMediaPlayer>
#include <QSlider>

class TrackWidget : public QWidget
{
    Q_OBJECT
public:
    TrackWidget(QWidget *parent);
    ~TrackWidget();
    void setTexts();
    void changeVolume(int value);
public slots:
    void playTrack();

protected:
    QLineEdit *name;
    QLineEdit *url;
    QPushButton *deleteBtn;
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QPushButton *stopBtn;
    QSlider * volume;

    QMediaPlayer *player;
};

#endif /*TRACK_WIDGET_H*/
