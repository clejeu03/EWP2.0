#ifndef QABSTRACTPARTITIONER_H
#define QABSTRACTPARTITIONER_H

#include <QtWidgets>

class QAbstractPartitioner : public QWidget
{
    Q_OBJECT
public:

    QAbstractPartitioner(int min, int max, QWidget *parent=0);

    Qt::Orientation orientation() const {return m_orientation;}
    int maximum() const {return m_maximum;}
    void setMaximum(int value){m_maximum = value;}
    int minimum() const {return m_minimum;}
    void setMinimum(int value){m_minimum = value;}
    bool inverted() const {return m_inverted;}
    void setInverted(bool state){m_inverted = state;}
    int singleStep() const {return m_singleStep;}
    void setSingleStep(int value){m_singleStep = value;}
    QPair < int, int > partition() const {return m_partition;}
    void setPartition(int value1, int value2){ m_partition = QPair<value1,value2>;}
    void setPartition(QPair<int, int> partition ){m_partition = partition;}
    int position() const {return m_position;}
    void setPosition(int value){m_position = value;}
    bool isHovered() const {return m_hovered;}


public slots:
    void setOrientation(Qt::Orientation orientation){m_orientation = orientation;}
    void setRange(int min, int max);
    void setPosition(int value);


signals:
    void rangeChanged(int min, int max);
    void positionChanged(int value);
    void enteredPartitioner();
    void exiteredPartitioner();


private:
    Qt::Orientation m_orientation;
    int m_maximum;
    int m_minimum;
    bool m_inverted;
    int m_singleStep;
    QPair < int, int > m_partition;
    int m_position;
    bool m_hovered;

};

#endif // QABSTRACTPARTITIONER_H
