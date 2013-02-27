#include "Timeline.h"

Timeline::Timeline()
{
    setDrawingStatus(false);
}

void Timeline::setDrawingStatus(bool status){
    m_drawingStatus = status;
}


int Timeline::getListSize(){
    QMapIterator<int, Video*> iterator(m_videoList);
    while (iterator.hasNext()) {
         iterator.next();
    }
    return iterator.key();
}

void Timeline::addVideo(Video* video){
    m_videoList.insert(m_videoList.end().key(), video);
}

void Timeline::removeVideo(Video* video){
    QMap<int, Video*>::iterator iterator;
    int index = m_videoList.key(video);
    m_videoList.remove(index);
    for(iterator.key() == index+1; iterator!=m_videoList.end(); ++iterator){
        Video * value = value(iterator.key());
        m_videoList.insert(iterator.key()--, value);
    }
}

void Timeline::setReverse(Video* video){
    if(video->getReverse()){
        video->setReverse(false);
    }else{
        video->setReverse(true);
    }
}

void Timeline::moveVideo(Video* video, int newPos){
    int index = key(video);
    Video* tmp = m_videoList.value(newPos);
    m_videoList.insert(newPos, m_videoList.value(index));
    m_videoList.insert(index, tmp);
}

