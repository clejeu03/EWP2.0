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

class Chutier : public QWidget
{
    Q_OBJECT
    private :
        QListWidget *mediaList;
        QListWidget *weightList;
        QListWidget *playList;
        QLabel *titre;
        QLabel *titreMedia;

        QVBoxLayout *vLayout;
        QSplitter *splitter;
        QHBoxLayout *cLayout;
        QSplitter *CSplitter;

    public:
        void Add(QList<QString> list);
        void Weight(QList<QString> list);
        void Play(QList<QString> list);

        Chutier(QWidget *parent=0);
        virtual ~Chutier();
        void deplier();
};

#endif // CHUTIER_H
