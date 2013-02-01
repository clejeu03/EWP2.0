#include "track.h"
#include <QPainter>

Track::Track(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
{
    // need to disable this flag to draw inside a QDeclarativeItem
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

Track::Track(QString name, int duration, QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
{
    // need to disable this flag to draw inside a QDeclarativeItem
    setFlag(QGraphicsItem::ItemHasNoContents, false);
    setName(name);
    setDuration(duration);
}

int Track::receiveValues(int value){

    Q

    qDebug() << " Valuer cpp :" << value;
    return value;
}

QString Track::name() const
{
     return m_name;
}
int Track::duration() const
{
    return m_duration;
}

 void Track::setName(const QString &name)
 {
     m_name = name;
 }

 void Track::setDuration(const int &duration){
     m_duration = duration;
 }

void Track::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPen pen(Qt::black, 2);
    painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawEllipse(5.0, 5.0, 5.0, 5.0);

    //painter->drawEllipse(5.0, 5.0, 10.0, 10.0);
}
