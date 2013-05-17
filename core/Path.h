#ifndef PATH_H
#define PATH_H

#include "QMap"
#include "QPair"
#include "Video.h"
#include "QDebug"
#include "QObject"

class Path : public QObject
{
    Q_OBJECT
public:
    Path(QObject *parent=0);
    Path(const Path&);
    inline QMap<Video*, QPair<int, int> > getSequences(){return m_sequences;}
    void addEntry(Video* video, int value, int value2);

private :
    QMap<Video*, QPair<int,int> > m_sequences;


};

#endif // PATH_H
