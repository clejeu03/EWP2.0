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
#include <QToolButton>

class Chutier : public QWidget
{
    Q_OBJECT
    private :
        QListWidget *mediaList;
        QListWidget *weightList;
        QListWidget *playList;
        QLabel *titre;
        QLabel *titleClip;
        QLabel *titreMedia;

        QVBoxLayout *vLayout;
        QSplitter *splitter;
        QHBoxLayout *cLayout;
        QSplitter *CSplitter;

    public:
        void Add(QList<QString> list);
        void Weight(QList<QString> list);
        void Play(QList<QIcon> list);

        Chutier(QWidget *parent=0);
        virtual ~Chutier();
        void deplier();

    private slots:
        void updateCurrentweightListItem(/*QListWidget *listeSource, QListWidget *listeTarget*/);
        void updateCurrentmediaListItem();
        //void updateCurrentplayListItem();

};

#endif // CHUTIER_H
