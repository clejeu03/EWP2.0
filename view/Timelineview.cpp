#include "Timelineview.h"
#include "core/Video.h"
#include "core/Timeline.h"

#include <qdeclarative.h>
#include <QVBoxLayout>
#include <QDeclarativeContext>
#include <QDeclarativeView>

#include <QDockWidget>
#include <QListWidget>

TimelineView::TimelineView(Timeline *timeline, QWidget *parent):QWidget(parent)
{
    m_timeline = timeline;

    //qmlRegisterType<Timeline>("Timeline", 1, 0, "Slider");

    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();

    /****===============TESTS=======================*****/
    Video *video1 = new Video("/home/cecilia/Vidéos/bunny.mp4");
    Video *video2 = new Video("/home/cecilia/Vidéos/ludovik.mp4");

    QMap<int, Video*> sourceMap;
    sourceMap[0]= video1;
    sourceMap[1] = video2;
    Timeline *timeline = new Timeline(sourceMap);

    qDebug() << "__________CREATION__________";
    qDebug() << "drawing status : " << timeline->getDrawingStatus();
    qDebug() << "list size : " << timeline->getVideoList();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();

    //timeline.addVideo(video1);
    //timeline.addVideo(video2);

    qDebug() << "__________ADDING__________";
    qDebug() << "list size : " << timeline->getListSize();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(0)->getCompleteName();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(1)->getCompleteName();

    /****============================================*****/

    QStringList dataList;
    dataList.append("Bunny.mp3");
    dataList.append("Track02");
    QDeclarativeView *view = new QDeclarativeView;
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    view->setSource(QUrl::fromLocalFile("../EWP2.0/view/resources/Timeline/app.qml"));

    layout->addWidget(view);
    container->setLayout(layout);

}

