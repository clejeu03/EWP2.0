#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QWidget>
#include "core/Path.h"

class Timeline;

class TimelineView : public QWidget
{
    Q_OBJECT
public:
    TimelineView(Timeline *timeline, QWidget *parent=0);
private:
    Timeline *m_timeline;
    QList<QPair <int, int> > m_points;

private slots:
    void receiveValues(int value, int value2);
    void parseData(Path *path);
};


#endif // TIMELINEVIEW_H
