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
   mediaList->size();
   mediaList->addItem("media1");
   mediaList->addItem("media2");
   mediaList->addItem("media3");
   mediaList->addItem("media4");

   splitter->addWidget(titre);
   splitter->addWidget(mediaList);

   setContentsMargins(1,2,3,4);

}

Chutier::~Chutier()
{

}

void Chutier::deplier()
{

}
