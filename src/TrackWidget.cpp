#include "TrackWidget.h"
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qwidget.h>

TrackWidget::TrackWidget(QWidget *parent) : QWidget(parent)

{
    this->setLayout(new QVBoxLayout(this));
    name = new QLineEdit(this);
    url = new QLineEdit(this);
    deleteBtn = new QPushButton(this);
    playBtn = new QPushButton(this);
    pauseBtn = new QPushButton(this);
    stopBtn = new QPushButton(this);

    QWidget * w = new QWidget(this);
    w->setLayout(new QHBoxLayout(w));
    w->layout()->addWidget(name);
    w->layout()->addWidget(deleteBtn);
    layout()->addWidget(w);
    layout()->addWidget(url);

    QWidget * controls = new QWidget(this);
    controls->setLayout(new QHBoxLayout(controls));
    controls->layout()->addWidget(playBtn);
    controls->layout()->addWidget(pauseBtn);
    controls->layout()->addWidget(stopBtn);
    layout()->addWidget(controls);
}

TrackWidget::~TrackWidget() {}
