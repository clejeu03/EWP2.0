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

class Chutier : public QWidget
{
    Q_OBJECT
    private :
        QListWidget *mediaList;
        QLabel *titre;
        QVBoxLayout *vLayout;
        QSplitter *splitter;

    public:
        Chutier(QWidget *parent=0);
        virtual ~Chutier();
        void deplier();
};

#endif // CHUTIER_H
