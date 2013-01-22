#ifndef PINCEAU_H
#define PINCEAU_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QLinearGradient>

class Pinceau : public QWidget
{
    Q_OBJECT
    private:
        QLabel *PLabel;
    public:
        Pinceau(QWidget *parent=0);
        virtual ~Pinceau();
        void paintEvent(QPaintEvent *event);
};

#endif // PINCEAU_H
