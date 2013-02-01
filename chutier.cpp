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

   m_State = STATE_DEFAULT;

   icone = new QPixmap("resources/exit.png");
   exitIcon = new QIcon(*icone);
   m_Exit = new QAction(*exitIcon,"fermer",this);

   this->addAction(m_Exit);

   connect(m_Exit, SIGNAL(triggered()), this, SLOT(hide()));
   connect(mediaList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentweightmediaListItem(/*mediaList,weightList*/)));
   connect(mediaList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentweightplayListItem(/*mediaList,weightList*/)));

   connect(weightList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentmediaweightListItem(/*weightList,mediaList*/)));
   connect(weightList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentmediaplayListItem(/*playList,weightList*/)));

   connect(playList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentplayweightListItem(/*playList,weightList*/)));
   connect(playList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(updateCurrentplaymediaListItem(/*playList,weightList*/)));

}

void Chutier::updateCurrentplayweightListItem(){

    QListWidgetItem *item = playList->currentItem();
    //on recupere la ligne de l'item
    int itemRow = playList->row(item);

    weightList->setCurrentRow(itemRow);
}

void Chutier::updateCurrentplaymediaListItem(){

    QListWidgetItem *item = playList->currentItem();
    //on recupere la ligne de l'item
    int itemRow = playList->row(item);

    mediaList->setCurrentRow(itemRow);
}

void Chutier::updateCurrentweightplayListItem(){

    QListWidgetItem *item = weightList->currentItem();
    //on recupere la ligne de l'item
    int itemRow = weightList->row(item);

    playList->setCurrentRow(itemRow);
}

void Chutier::updateCurrentweightmediaListItem(/*QListWidget *listeSource, QListWidget *listeTarget*/){

    QListWidgetItem *item = mediaList->currentItem();
    //on recupere la ligne de l'item
    int itemRow = mediaList->row(item);

    weightList->setCurrentRow(itemRow);
}

void Chutier::updateCurrentmediaweightListItem(){

    QListWidgetItem *item = weightList->currentItem();
    //on recupere la ligne de l'item
    int itemRow = weightList->row(item);

    mediaList->setCurrentRow(itemRow);

    m_State = STATE_DEFAULT;

   icone = new QPixmap("resources/exit.png");
   exitIcon = new QIcon(*icone);
   m_Exit = new QAction(*exitIcon,"fermer",this);

   this->addAction(m_Exit);

   connect(m_Exit, SIGNAL(triggered()), this, SLOT(hide()));

}

void Chutier::updateCurrentmediaplayListItem(){

    QListWidgetItem *it = mediaList->currentItem();
    //on recupere la ligne de l'item
    int itRow = mediaList->row(it);

    playList->setCurrentRow(itRow);
}

void Chutier::Add(QList<QString> list){
    if(mediaList)
    {
       if(!list.isEmpty()){
            mediaList->addItem(list.last());
            if(playList)
            {
                QListWidgetItem *icone = new QListWidgetItem();
                icone->setIcon(QIcon("resources/play.png"));
                playList->addItem(icone);
            }
        }
    }
}

void Chutier::Play(QListWidgetItem *button){
            playList->addItem(button);
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


void Chutier::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    switch(m_State)
    {
        case STATE_DEFAULT:
            icone = NULL;
            m_Exit->setIcon(QIcon("resources/exit.png"));
            break;
        case STATE_HOVERED:
            icone = NULL;
            m_Exit->setIcon(QIcon("resources/exit_hovered.png"));
            break;
        case STATE_CLICKED:
            icone = NULL;
            m_Exit->setIcon(QIcon("resources/exit_clicked.png"));
            break;
    }

    QLinearGradient gradient(0,0,0,15);
    gradient.setColorAt(0.0,QColor("#d9d9d9"));
    gradient.setColorAt(0.5,QColor("#c1c1c1"));

    QBrush brush(gradient);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    static const int points[] = {5,0,(5/2),(5/2),0,5,0,15,300,15,300,5,(295+(5/2)),(5/2),295,0};
    QPolygon polygon;
    polygon.setPoints(8,points);

    painter.drawPolygon(polygon, Qt::OddEvenFill);

    //dessin des actions
    for(int i=0; i<this->actions().size(); ++i)
    {
        QAction *action = this->actions().at(i);
        painter.drawPixmap(280,2,action->icon().pixmap(12,12));
    }

}

void Chutier::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 250 && point.x() < 300)
    {
        m_State = STATE_HOVERED;
        update(275,2,18,18);
    }
}

void Chutier::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);

    m_State = STATE_DEFAULT;
    update(275,2,18,18);
}

void Chutier::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 250 && point.x() < 300)
    {
        m_State = STATE_CLICKED;
        update(275,2,18,18);
    }
}

void Chutier::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 250 && point.x() < 300)
    {
        if(underMouse())
        {
             m_State = STATE_HOVERED;
        }
        else{
             m_State = STATE_DEFAULT;
        }
    }
    m_Exit->trigger(); //on force le signal trigger de m_Exit
    update(275,2,18,18);
}

void Chutier::hide()
{
    this->setVisible(false);

}

void Chutier::showEvent(QShowEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(true);
}

void Chutier::hideEvent(QHideEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(false);
}
