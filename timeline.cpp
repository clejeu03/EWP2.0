#include "timeline.h"

Timeline::Timeline(QWidget *parent):QWidget(parent)
{

    clipList = new QListWidget(this);
    clipList->resize(700,300);
    clipList->addItem("clip1 \tsequence video...");
    clipList->addItem("clip2 \tsequence video...");
    clipList->addItem("clip3 \tsequence video...");
    clipList->addItem("clip4 \tsequence video...");

}

Timeline::~Timeline()
{

}
