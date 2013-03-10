#ifndef BRUSH_H
#define BRUSH_H

//#include "Visible.h"
#include <QString>
#include <QColor>


class Brush {

 public:
    enum Shape {    CORNER,
                    BEZIER,
                    SEMIBEZIER};

    Brush(){
        m_thight = 20;
        m_color = QColor(Qt::darkRed);
        m_shape = BEZIER;
    }
    inline void setShape(Shape shape);
    inline void setThickness(float thight){m_thight = thight;}
    inline void setColor(int r, int g, int b){m_color = QColor(r,g,b);}//from RGB values
    inline void setColor(QString name){m_color = QColor(name);}//from String
    inline Shape getShape(){return m_shape;}
    inline QColor getColor(){return m_color;}
    inline QString getColor(){return m_color.name();}//format héxadecimal
    inline float getThickness(){return m_thight;}

 private:

    Shape m_shape;
    float m_thight;
    QColor m_color; //Format RGB
};

#endif // BRUSH_H
