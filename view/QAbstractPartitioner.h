#ifndef QABSTRACTPARTITIONER_H
#define QABSTRACTPARTITIONER_H

#include <QtWidgets>

class QAbstractPartitioner : public QWidget
{
    Q_OBJECT
public:

    QAbstractPartitioner(QWidget *parent=0);
    QAbstractPartitioner(int min, int max, QWidget *parent=0){
        this->setMinimum(min);
        this->setMaximum(max);
        m_orientation = Qt::Horizontal;
        m_inverted = false;
        m_hovered = false;
        m_position = m_minimum;
        m_singleStep = 1;
    }

    inline Qt::Orientation orientation() const {return m_orientation;}
    inline int maximum() const {return m_maximum;}
    inline void setMaximum(int value){m_maximum = value;}
    inline int minimum() const {return m_minimum;}
    inline void setMinimum(int value){m_minimum = value;}
    inline bool inverted() const {return m_inverted;}
    inline void setInverted(bool state){m_inverted = state;}
    inline int singleStep() const {return m_singleStep;}
    inline void setSingleStep(int value){m_singleStep = value;}
    inline QPair < int, int > partition() const {return m_partition;}
    inline void setPartition(int value1, int value2){ m_partition = QPair<int, int>(value1,value2);}
    inline void setPartition(QPair<int, int> partition ){m_partition = partition;}
    inline int position() const {return m_position;}
    inline void setPosition(int value){m_position = value;}
    inline bool isHovered() const {return m_hovered;}


public slots:
    void setOrientation(Qt::Orientation orientation){m_orientation = orientation;}


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
