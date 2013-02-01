#include "track.h"
#include "editor.h"
#include <QPainter>

Track::Track(QDeclarativeItem *parent)
    : QDeclarativeItem(parent)
{
    resultList = new QList<QObject*>;
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

int Track::receiveValues(int value, int value2){

    if(resultList->empty() == true){
        resultList->append(new Editor("/home/cecilia/Vidéos/bunny.mp4", value, value2));
    }else{
        resultList->append(new Editor("/home/cecilia/Vidéos/ludovik.mp4", value, value2));
    }

    qDebug() << "List :" << resultList;
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
