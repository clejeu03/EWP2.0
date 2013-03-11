#include "Timelineview.h"
#include "core/Video.h"
#include "core/Timeline.h"

#include <qdeclarative.h>
#include <QVBoxLayout>
#include <QDeclarativeContext>
#include <QDeclarativeItem>
#include <QDeclarativeView>

TimelineView::TimelineView(QWidget *parent):QWidget(parent)
{
    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();

    //Timeline *timeline = new Timeline();
    QList<QObject*> dataList;
    //Video *video = new Video("/home/cecilia/Vidéos/bunny.mp4");
    //qmlRegisterType<Track>("Timeline", 1, 0, "video");
    QDeclarativeView *view = new QDeclarativeView;
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    view->setSource(QUrl::fromLocalFile("../EWP2.0/view/resources/app.qml"));

    layout->addWidget(view);
    container->setLayout(layout);

}

