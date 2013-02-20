#include "Project.h"

#include <QDebug>

/*Constructor : create a new project*/
Project::Project(QString name, QString path){
    m_name = name;
    QFileInfo info(path);
    if(info.isDir()){
        m_path = path;
    }else{
        qDebug() << "EWP-Error : " << path << " is not a dir." ;
    }
}

/*Import a new video into the project*/
void Project::importVideo(QString videoPath){
   if(m_videoList.size()<20){
        Video *video = new Video(videoPath);
        if(video){
            m_videoList.append(video);
        }else{
            qDebug() << "EWP-Error : " << video->getName() << " is not a valid video." ;
        }
    }else{
       qDebug() << "EWP-Error : you've reach the maximum video files into your project." ;
   }
}

/*Suppress a video from the project by video index*/
void Project::removeVideo(int index){
    if(0 < index && index < m_videoList.size()){
        delete(m_videoList.takeAt(index));
    }else{
        qDebug() << "EWP-Error : " << index << " is not a valid index." ;
    }
}

/*Overwritting operator == */
bool Project::operator==(Project a){
    return m_name == a.getProjectName() && m_path ==a.getProjectPath();
}


