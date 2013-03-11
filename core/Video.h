#ifndef VIDEO_H
#define VIDEO_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QString>
#include <QFileInfo>


//class Project;
//class Timeline;
//class VideoPart;
using namespace cv;
class Video {

 public:
    Video(QString path){
        m_path = path;
        m_completeName = path.remove(0, ( path.lastIndexOf("/")+1) );

        VideoCapture * capture = new VideoCapture(m_path.toStdString());
        int fps = capture->get(CV_CAP_PROP_FPS);
        double total_frame = capture->get(CV_CAP_PROP_FRAME_COUNT);
        m_duration = qRound(total_frame/fps);

        QFileInfo info(m_path);
        m_name = info.completeBaseName();
        m_format = info.completeSuffix();
        m_weight = info.size()/1000000.;
        m_roundWeight = qRound(m_weight);
        m_timelinePresence = false;
        m_reverse = false;

    }

    inline void setName(QString name){m_name = name;}
    inline void setCompleteName(QString completeName){m_completeName = completeName;}
    inline void setPath(QString path){m_path = path;}
    inline void setFormat(QString format){m_format = format;}
    inline void setWeight(double weight){m_weight = weight; m_roundWeight = qRound(m_weight);}
    inline void setReverse(bool reverse){m_reverse = reverse;}
    inline void setDuration(qint64 duration){m_duration = duration;}
    inline void setScript(QString script){m_script = script;}
    inline void setTimelinePresence(bool timelinePresence){m_timelinePresence = timelinePresence;}

    inline QString getName(){return m_name;}
    inline QString getCompleteName(){return m_completeName;}
    inline QString getPath(){return m_path;}
    inline QString getFormat(){return m_format;}
    inline double getWeight(){return m_weight;}
    inline double getRoundWeight(){return m_roundWeight;}
    inline bool getReverse(){return m_reverse;}
    inline qint64 getDuration(){return m_duration;}
    inline QString getScript(){return m_script;}
    inline bool getTimelinePresence(){return m_timelinePresence;}

 private:
    QString m_path;
    QString m_completeName; //ex : bunny.mp4
    QString m_name; //ex : bunny
    QString m_format;//ex : mp4
    qint64 m_duration;// en secondes
    double m_weight; //ex: 5.514532 MB
    double m_roundWeight; //ex: 5.5 MB
    bool m_timelinePresence;
    QString m_script;
    bool m_reverse;

    //Project *project;         DAFUUUQ ???
    /*Timeline *timeline;
    VideoPart *VideoPartAssoc;*/
};

#endif // VIDEO_H
