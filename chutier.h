#ifndef CHUTIER_H
#define CHUTIER_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QStyleFactory>
#include <QListWidget>
#include <iostream>
#include <QSplitter>
#include <QList>
#include <QString>
#include <QAction>
#include <QPixmap>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QPainter>

class Chutier : public QWidget
{
    Q_OBJECT
    public:
        void Add(QList<QString> list);
        void Weight(QList<QString> list);
        void Play(QList<QString> list);

        Chutier(QWidget *parent=0);
        virtual ~Chutier();
        void paintEvent(QPaintEvent *event);
        void enterEvent(QEvent *event);
        void leaveEvent(QEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void deplier();
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
        QListWidget *mediaList;
        QListWidget *weightList;
        QListWidget *playList;
        QLabel *titre;
        QLabel *titreMedia;

        QVBoxLayout *vLayout;
        QSplitter *splitter;
        QHBoxLayout *cLayout;
        QSplitter *CSplitter;

};

#endif // CHUTIER_H
