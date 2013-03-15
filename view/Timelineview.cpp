#include "Timelineview.h"
#include "core/Video.h"
#include "core/Timeline.h"

#include <qdeclarative.h>
#include <QVBoxLayout>
#include <QDeclarativeContext>
#include <QDeclarativeItem>
#include <QDeclarativeView>

TimelineView::TimelineView(Timeline *timeline, QWidget *parent):QWidget(parent)
{
    m_timeline = timeline;

    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();


    QList<QObject*> dataList;
    QDeclarativeView *view = new QDeclarativeView;
    QDeclarativeContext *ctxt = view->rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
    view->setSource(QUrl::fromLocalFile("../EWP2.0/view/resources/app.qml"));

    layout->addWidget(view);
    container->setLayout(layout);

}

