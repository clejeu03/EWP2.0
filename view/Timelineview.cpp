#include "Timelineview.h"
#include "core/Video.h"
#include "core/Timeline.h"

#include <qdeclarative.h>
#include <QVBoxLayout>
#include <QDeclarativeContext>
#include <QGraphicsObject>
#include <QDeclarativeView>
#include <QDebug>
#include <QDockWidget>
#include <QListWidget>

TimelineView::TimelineView(Timeline *timeline, QWidget *parent):QWidget(parent)
{
    m_timeline = timeline;

    //qmlRegisterType<Timeline>("Timeline", 1, 0, "Slider");

    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();

    QStringList dataList;
    dataList.append("Bunny.mp3");
    dataList.append("Track02");
    QDeclarativeView *view = new QDeclarativeView;
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    view->setSource(QUrl::fromLocalFile("../EWP2.0/view/resources/Timeline/app.qml"));

    layout->addWidget(view);
    container->setLayout(layout);

    //Temporary !
    QObject *slider = view->rootObject();
    QObject::connect(slider, SIGNAL(sendValues(int, int)),this, SLOT(receiveValues(int, int)));
    QObject::connect(slider, SIGNAL(goEditing()),this, SLOT(edit()));
}

void TimelineView::receiveValues(int value, int value2){
    qDebug() << "value1 : " << value << " value2 : " << value2 ;
}

void TimelineView::edit(){
    qDebug() << "edit !" ;
}


