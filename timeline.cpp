#include "timeline.h"

Timeline::Timeline(QWidget *parent):QWidget(parent)
{

    clipList = new QListWidget(this);
    clipList->resize(700,300);
    clipList->addItem("clip1 \tsequence video...");
    clipList->addItem("clip2 \tsequence video...");
    clipList->addItem("clip3 \tsequence video...");
    clipList->addItem("clip4 \tsequence video...");

    m_State = STATE_DEFAULT;

    icone = new QPixmap("resources/exit.png");
    exitIcon = new QIcon(*icone);
    m_Exit = new QAction(*exitIcon,"fermer",this);

    this->addAction(m_Exit);

    setMouseTracking(true);
    connect(m_Exit, SIGNAL(triggered()), this, SLOT(hide()));
}

Timeline::~Timeline()
{

}

void Timeline::paintEvent(QPaintEvent *event)
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

    static const int points[] = {5,0,(5/2),(5/2),0,5,0,15,700,15,700,5,(695+(5/2)),(5/2),695,0};
    QPolygon polygon;
    polygon.setPoints(8,points);

    painter.drawPolygon(polygon, Qt::OddEvenFill);

    //dessin des actions
    for(int i=0; i<this->actions().size(); ++i)
    {
        QAction *action = this->actions().at(i);
        painter.drawPixmap(680,2,action->icon().pixmap(12,12));
    }

}

/*
void Timeline::mouseMoveEvent(QMouseEvent *event)
{

    //QPoint point = this->mapFromGlobal(QCursor::pos());

    if(event.x() > 675 && event.x() < 694){
       //if(point.y() > 1 && point.y() < 15)
       //{
            std::cout << "survol" << std::endl;
            m_State = STATE_HOVERED;

            update(675,2,18,18); //on met à jour la zone de l'icone
       // }
   }

}
*/

void Timeline::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 650 && point.x() < 700)
    {
        m_State = STATE_HOVERED;
        update(675,2,18,18);
    }
}

void Timeline::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);

    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 650 && point.x() < 700)
    {
        m_State = STATE_DEFAULT;
        update(675,2,18,18);
    }
}

void Timeline::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 650 && point.x() < 700)
    {
        m_State = STATE_CLICKED;
        update(675,2,18,18);
    }
}

void Timeline::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(underMouse())
    {
         m_State = STATE_HOVERED;
    }
    else{
         m_State = STATE_DEFAULT;
    }
    m_Exit->trigger(); //on force le signal trigger de m_Exit
    update(675,2,18,18);
}

void Timeline::hide()
{
    this->setVisible(false);

}

void Timeline::showEvent(QShowEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(true);
}

void Timeline::hideEvent(QHideEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(false);
}
