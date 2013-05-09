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

private slots:
    //Temporary !
    void receiveValues(int, int);
    void edit();

};


#endif // TIMELINEVIEW_H
