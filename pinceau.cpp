#include "pinceau.h"

Pinceau::Pinceau(QWidget *parent):QWidget(parent)
{
    QFont font;
    font.setBold(true);
    font.setPointSize(16);

    PLabel = new QLabel("Pinceau", this);
    PLabel->setFont(font);
    PLabel->setAlignment(Qt::AlignTop);

    //a enlever par la suite
    PLabel->resize(300,200);

    m_State = STATE_DEFAULT;

    icone = new QPixmap("resources/exit.png");
    exitIcon = new QIcon(*icone);
    m_Exit = new QAction(*exitIcon,"fermer",this);

    this->addAction(m_Exit);

    connect(m_Exit, SIGNAL(triggered()), this, SLOT(hide()));
}

Pinceau::~Pinceau()
{

}

void Pinceau::paintEvent(QPaintEvent *event)
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

void Pinceau::enterEvent(QEvent *event)
{
    Q_UNUSED(event);

    //position curseur à récupérer
    //http://qt.developpez.com/doc/4.7/qmouseevent/

    m_State = STATE_HOVERED;
    update(275,2,18,18); //on met à jour la zone de l'icone
}

void Pinceau::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_State = STATE_DEFAULT;
    update(275,2,18,18);
}

void Pinceau::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_State = STATE_CLICKED;
    update(275,2,18,18);
}

void Pinceau::mouseReleaseEvent(QMouseEvent *event)
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
    update(275,2,18,18);
}

void Pinceau::hide()
{
    this->setVisible(false);

}

void Pinceau::showEvent(QShowEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(true);
}

void Pinceau::hideEvent(QHideEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(false);
}
