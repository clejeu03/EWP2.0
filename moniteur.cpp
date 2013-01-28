#include <QFile>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "moniteur.h"
#include "player/Player.h"

using namespace cv;

Moniteur::Moniteur(QWidget *parent):QWidget(parent)
{
    QFont Mfont;
    Mfont.setBold(true);
    Mfont.setPointSize(16);

    VideoCapture * capture = new VideoCapture("/home/big_buck_bunny.mp4");
   // Player *player = new Player(capture);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(player);
    player->resize(200,200);

    VideoCapture * capture = new VideoCapture("/home/damaris/Vidéos/big_buck_bunny.mp4");
    Player *player = new Player(capture);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(player);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    player->show();

    /*Setting CSS file*/
    QFile file("../player/playerStyleSheet.css");
    file.open(QFile::ReadOnly);
    QString playerStyleSheet = QLatin1String(file.readAll());
    player->setStyleSheet(playerStyleSheet);

    labMoniteur = new QLabel("Moniteur",this);
    labMoniteur->setFont(Mfont);
    labMoniteur->setAlignment(Qt::AlignTop);

    m_State = STATE_DEFAULT;

    icone = new QPixmap("resources/exit.png");
    exitIcon = new QIcon(*icone);
    m_Exit = new QAction(*exitIcon,"fermer",this);

    this->addAction(m_Exit);

    connect(m_Exit, SIGNAL(triggered()), this, SLOT(hide()));


}

Moniteur::~Moniteur()
{

}

void Moniteur::paintEvent(QPaintEvent *event)
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

void Moniteur::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 650 && point.x() < 700)
    {
        m_State = STATE_HOVERED;
        update(675,2,18,18);
    }
}

void Moniteur::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_State = STATE_DEFAULT;
    update(675,2,18,18);
}

void Moniteur::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint point = this->mapFromGlobal(QCursor::pos());

    if(point.x() > 650 && point.x() < 700)
    {
        m_State = STATE_CLICKED;
        update(675,2,18,18);
    }
}

void Moniteur::mouseReleaseEvent(QMouseEvent *event)
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

void Moniteur::hide()
{
    this->setVisible(false);

}

void Moniteur::showEvent(QShowEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(true);
}

void Moniteur::hideEvent(QHideEvent *e)
{
    Q_UNUSED(e);
    emit sig_show(false);
}
