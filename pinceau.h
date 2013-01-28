#ifndef PINCEAU_H
#define PINCEAU_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QLinearGradient>
#include <QPainter>
#include <QAction>
#include <QPixmap>

class Pinceau : public QWidget
{
    Q_OBJECT
    public:
        Pinceau(QWidget *parent=0);
        virtual ~Pinceau();
        void paintEvent(QPaintEvent *event);
        void enterEvent(QEvent *event);
        void leaveEvent(QEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
    signals:
        void sig_show(bool);
    public slots :
        void hide();
    protected:
        virtual void showEvent(QShowEvent *e);
        virtual void hideEvent(QHideEvent *e);
    private:
        enum buttonState
        {
             STATE_DEFAULT, STATE_HOVERED, STATE_CLICKED
        };
        buttonState m_State;
        QPixmap *icone;
        QAction *m_Exit;
        QIcon *exitIcon;
        QLabel *PLabel;
};

#endif // PINCEAU_H
