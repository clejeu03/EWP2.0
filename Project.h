#ifndef PROJECT_H
#define PROJECT_H

#include <vector>

#include "Video.h"

//class ProjectManager;

class Project {

 public:
    Project(QString name, QString path);

    void removeVideo(int index);
    void importVideo(QString videoPath);
    inline void setProjectPath(QString path){m_path = path;}
    inline void setProjectName(QString name){m_name = name;}

    inline QList<Video*> getVideoList(){return m_videoList;}
    inline QString getProjectPath(){return m_path;}
    inline QString getProjectCompletePath(){return m_path+"/"+m_name+".ewp";}
    inline QString getProjectName(){return m_name;}
    inline int getVideoListSize(){return m_videoList.size();}

    bool operator==(Project const a);

 private:
    QString m_name;
    QString m_path;
    QList<Video*> m_videoList;
    //ProjectManager *projectManager;
};

#endif // PROJECT_H
