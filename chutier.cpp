#include "chutier.h"

Chutier::Chutier(QWidget *parent):QWidget(parent)
{

   QFont font;
   font.setBold(true);
   font.setPointSize(16);

   titre = new QLabel("Chutier", this);
   titre->setFont(font);
   titre->setAlignment(Qt::AlignTop);
   splitter = new QSplitter(Qt::Vertical, this);
   mediaList = new QListWidget();
   weightList = new QListWidget();

   splitter->addWidget(titre);
   splitter->setStyleSheet("border : 1px solid #d9d9d9");
   setContentsMargins(1,2,3,4);

   QWidget *listcontainer = new QWidget(this); //widget chutier

   CSplitter = new QSplitter(Qt::Horizontal, this);
   cLayout = new QHBoxLayout;

   CSplitter->addWidget(mediaList);
   CSplitter->addWidget(weightList);
   cLayout->addWidget(CSplitter);
   listcontainer->setLayout(cLayout);
   splitter->addWidget(listcontainer);
   splitter->resize(300,400);

}

void Chutier::Add(QList<QString> list){
    mediaList->addItem(list.last());
}

void Chutier::Play(QList<QString> list){
    mediaList->addItem(list.last());
}

void Chutier::Weight(QList<QString> list){
    if(weightList)
    {
        if(!list.isEmpty())
            weightList->addItem(list.last());
    }
}

Chutier::~Chutier()
{

}

void Chutier::deplier()
{

}
