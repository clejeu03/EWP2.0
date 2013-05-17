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
    m_points = QList<QPair <int, int> >();

    //qmlRegisterType<Timeline>("Timeline", 1, 0, "Slider");

    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();

    QStringList dataList;
    dataList.append("bunny.mp4");
    dataList.append("bunny.mp4");
    QDeclarativeView *view = new QDeclarativeView;
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    view->setSource(QUrl::fromLocalFile("../EWP2.0/view/resources/Timeline/app.qml"));

    layout->addWidget(view);
    container->setLayout(layout);

    m_path = new Path();

    //Temporary !
    QObject *slider = view->rootObject();
    QObject::connect(slider, SIGNAL(sendValues(int, int)),this, SLOT(receiveValues(int, int)));
    QObject::connect(slider, SIGNAL(goEditing()),this, SLOT(parseData()));
}

void TimelineView::receiveValues(int value, int value2){

    m_points.append(QPair<int,int>(value, value2));
}

void TimelineView::parseData(){
    //Until the number of markers is lower than the number of videos, go on picking...

    if(m_points.size() == m_timeline->getListSize()){
        for(int i=0; i<m_points.size();++i){
            //Change the order of the points according to the video's reverse parameter
            //TODO test with a checkbox working for the reverse !
            m_path->addEntry(m_timeline->getVideoList().value(i), m_points.at(i).first, m_points.at(i).second);
         }
        m_timeline->setPath(m_path);
        m_timeline->render();
    }
}



