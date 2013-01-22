#include "timeline.h"

Timeline::Timeline(QWidget *parent):QWidget(parent)
{
   /* QFont Tfont;
    Tfont.setBold(true);
    Tfont.setPointSize(16);

    TLabel = new QLabel("Timeline", this);
    TLabel->setFont(Tfont);
    TLabel->setAlignment(Qt::AlignTop);*/

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
