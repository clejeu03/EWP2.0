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

