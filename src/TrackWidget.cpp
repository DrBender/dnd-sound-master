#include "TrackWidget.h"
#include <QAudioOutput>
#include <QDebug>
#include <QVBoxLayout>
#include <qslider.h>
#include <unistd.h>

TrackWidget::TrackWidget(QWidget *parent) : QWidget(parent)

{
    setObjectName("TrackWidget");
    this->setLayout(new QVBoxLayout(this));
    name = new QLineEdit(this);
    url = new QLineEdit(this);
    deleteBtn = new QPushButton(this);
    playBtn = new QPushButton(this);
    pauseBtn = new QPushButton(this);
    stopBtn = new QPushButton(this);
    volume = new QSlider(this);
    volume->setRange(0, 100);
    volume->setValue(50);

    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(""));

    QWidget *w = new QWidget(this);
    w->setLayout(new QHBoxLayout(w));
    w->layout()->addWidget(name);
    w->layout()->addWidget(deleteBtn);
    layout()->addWidget(w);
    layout()->addWidget(url);

    QWidget *controls = new QWidget(this);
    controls->setLayout(new QHBoxLayout(controls));
    controls->layout()->addWidget(playBtn);
    controls->layout()->addWidget(pauseBtn);
    controls->layout()->addWidget(stopBtn);
    layout()->addWidget(controls);
    layout()->addWidget(volume);

    connect(volume, &QSlider::valueChanged, this, &TrackWidget::changeVolume);
    connect(playBtn, &QPushButton::clicked, this, &TrackWidget::playTrack);

    setTexts();
    show();
}

TrackWidget::~TrackWidget() {}

void TrackWidget::setTexts()
{
    name->setText("name");
    url->setText("url");
    deleteBtn->setText("Delete");
    playBtn->setText("Play");
    pauseBtn->setText("Pause");
    stopBtn->setText("Stop");
}

void TrackWidget::changeVolume(int value) { player->setVolume(value); }

void TrackWidget::playTrack() { player->play(); }
