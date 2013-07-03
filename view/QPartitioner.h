#ifndef QPARTITIONER_H
#define QPARTITIONER_H

#include "QAbstractPartitioner.h"

class QPartitioner : public QAbstractPartitioner
{
    Q_OBJECT
public:
    explicit QPartitioner(int min, int max, QAbstractPartitioner *parent = 0);
    
signals:
    
public slots:
    
};

#endif // QPARTITIONER_H
