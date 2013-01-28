#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QLinearGradient>
#include <QPixmap>
#include <QAction>
#include <iostream>

class Timeline : public QWidget
{
    Q_OBJECT
    public:
        Timeline(QWidget *parent=0);
        virtual ~Timeline();
        void paintEvent(QPaintEvent *event);
        void enterEvent(QEvent *event);
        void leaveEvent(QEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
    signals :
        void sig_show(bool);
    public slots:
        void hide();
    protected :
        virtual void showEvent(QShowEvent *e);
        virtual void hideEvent(QHideEvent *e);
    private :
        enum buttonState
        {
             STATE_DEFAULT, STATE_HOVERED, STATE_CLICKED
        };
        buttonState m_State;
        QPixmap *icone;
        QAction *m_Exit;
        QIcon *exitIcon;
        QListWidget *clipList;
};

#endif // TIMELINE_H

