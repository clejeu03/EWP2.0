#include "chutier.h"

Chutier::Chutier(QWidget *parent):QWidget(parent)
{

   QFont font;
   font.setBold(true);
   font.setPointSize(16);

   QFont font2;
   font2.setBold(true);
   font2.setPointSize(11);

   titre = new QLabel("Chutier", this);
   titre->setFont(font);
   titre->setAlignment(Qt::AlignTop);
   splitter = new QSplitter(Qt::Vertical, this);
   mediaList = new QListWidget();
   weightList = new QListWidget();
   playList = new QListWidget();


   mediaList->addItem("Clip");
   mediaList->setFont(font2);
   weightList->addItem("Poids (MB)");
   weightList->setFont(font2);
   playList->addItem("Lecture");
   playList->setFont(font2);

   splitter->addWidget(titre);
   splitter->setStyleSheet("border : 1px solid #d9d9d9");
   setContentsMargins(1,2,3,4);

   QWidget *listcontainer = new QWidget(this); //widget chutier

   CSplitter = new QSplitter(Qt::Horizontal, this);
   cLayout = new QHBoxLayout;

   CSplitter->addWidget(mediaList);
   CSplitter->addWidget(weightList);
   CSplitter->addWidget(playList);
   cLayout->addWidget(CSplitter);
   listcontainer->setLayout(cLayout);
   splitter->addWidget(listcontainer);
   splitter->resize(300,400);


   connect(mediaList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentweightListItem(/*mediaList,weightList*/)));
   connect(weightList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentmediaListItem(/*weightList,mediaList*/)));
}

void Chutier::updateCurrentweightListItem(/*QListWidget *listeSource, QListWidget *listeTarget*/){

    QListWidgetItem *item = mediaList->currentItem();
    //on recupere la ligne de l'item
    int itemRow = mediaList->row(item);

    weightList->setCurrentRow(itemRow);
}

void Chutier::updateCurrentmediaListItem(){

    QListWidgetItem *item = weightList->currentItem();
    //on recupere la ligne de l'item
    int itemRow = weightList->row(item);

    mediaList->setCurrentRow(itemRow);
    mediaList->currentItem()->setCheckState(Qt::Checked);
}

void Chutier::Add(QList<QString> list){
    if(mediaList)
    {
        if(!list.isEmpty()){
            mediaList->addItem(list.last());
        }
    }
}

void Chutier::Play(QList<QIcon> list){
    if(playList)
    {
        if(!list.isEmpty())
    playList->addItem(list.last());
    }
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
