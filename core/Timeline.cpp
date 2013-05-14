#include "Timeline.h"

Timeline::Timeline()
{
    setDrawingStatus(false);
    m_videoList = QMap<int, Video*>();
    m_videoUtils = new VideoUtils();
}

//Constructor used to recover a recorded work session
Timeline::Timeline(QMap<int, Video*> sourceMap)
{
    setDrawingStatus(false);
    m_videoList = sourceMap;
}

void Timeline::setDrawingStatus(bool status){
    m_drawingStatus = status;
}

//Add a video at the end of the video list
void Timeline::addVideo(Video* video){
    if(m_videoList.isEmpty()){
        m_videoList.insert(0, video);
    }else{
        m_videoList.insert(getListSize(),  video);
    }
}

//Remove a video by name
void Timeline::removeVideo(Video* video){
    int index = m_videoList.key(video);
    m_videoList.remove(index);
    for(int i = index+1; i< getListSize()+1; ++i){
        switchVideo(i, i-1);
    }
}

//Remove a video by its position in the list
void Timeline::removeVideo(int index){
    m_videoList.remove(index);
    for(int i = index+1; i< getListSize()+1; ++i){
        switchVideo(i, i-1);
    }
}

//Switch on/off the reverse status of the video
void Timeline::setReverse(Video* video){
    if(video->getReverse()){
        video->setReverse(false);
    }else{
        video->setReverse(true);
    }
}

//Switch the video to a new position in the video list
void Timeline::switchVideo(Video* video, int newPos){
    int index = m_videoList.key(video);
    if(m_videoList.contains(newPos)){
        Video* tmp = m_videoList.value(newPos);
        m_videoList.insert(newPos, m_videoList.value(index));
        m_videoList.insert(index, tmp);
    }else{
        m_videoList.insert(newPos, video);
        m_videoList.remove(index);
    }
}

//Switch two video by their names
void Timeline::switchVideo(Video* source, Video* target){
    int sIndex = m_videoList.key(source);
    int tIndex = m_videoList.key(target);
    if(m_videoList.contains(tIndex)){
        Video* tmp = m_videoList.value(tIndex);
        m_videoList.insert(tIndex, m_videoList.value(sIndex));
        m_videoList.insert(sIndex, tmp);
    }else{
        m_videoList.insert(tIndex, source);
        m_videoList.remove(sIndex);
    }
}

//Switch two videos by their positions in the video list
void Timeline::switchVideo(int pos, int newPos){
    if(m_videoList.contains(newPos)){
        Video* tmp = m_videoList.value(newPos);
        m_videoList.insert(newPos, m_videoList.value(pos));
        m_videoList.insert(pos, tmp);
    }else{
        m_videoList.insert(newPos, m_videoList.value(pos));
        m_videoList.remove(pos);
    }
}

