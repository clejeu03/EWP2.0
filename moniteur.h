#ifndef MONITEUR_H
#define MONITEUR_H

#include <QWidget>
#include <QLabel>

class Moniteur : public QWidget
{
    Q_OBJECT
    private:
        QLabel *labMoniteur;
    //player
    public:
        Moniteur(QWidget *parent=0);
        virtual ~Moniteur();
};

#endif // MONITEUR_H

