#include "Path.h"

Path::Path(QObject *parent):QObject(parent)
{
    m_sequences = QMap<Video*, QPair<int,int> >();
}

Path::Path(const Path& path):QObject(NULL){
    m_sequences = path.m_sequences;
}

void Path::addEntry(Video *video, int value, int value2){
    m_sequences.insert(video, QPair<int,int>(value, value2));
}
