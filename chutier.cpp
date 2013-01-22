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
   mediaList->resize(300,600);
   mediaList->addItem("media1");
   mediaList->addItem("media2");
   mediaList->addItem("media3");
   mediaList->addItem("media4");

   splitter->addWidget(titre);
   splitter->addWidget(mediaList);
   splitter->setStyleSheet("border : 1px solid #d9d9d9");
   setContentsMargins(1,2,3,4);

}

Chutier::~Chutier()
{

}

void Chutier::deplier()
{

}
