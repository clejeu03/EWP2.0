#include "Path.h"

Path::Path(QObject *parent):QObject(parent)
{
    m_sequences = QMap<Video*, QPair<int, int> >();
}

void Path::addEntry(Video *video, int value, int value2){
    m_sequences.insert(video, QPair<int,int>(value, value2));
}
