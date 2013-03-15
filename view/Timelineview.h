#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QWidget>

class Timeline;

class TimelineView : public QWidget
{
    Q_OBJECT
public:
    TimelineView(Timeline *timeline, QWidget *parent=0);
private:
    Timeline *m_timeline;

};

#endif // TIMELINEVIEW_H
