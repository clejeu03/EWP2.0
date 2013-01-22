#include "moniteur.h"

Moniteur::Moniteur(QWidget *parent):QWidget(parent)
{
    QFont Mfont;
    Mfont.setBold(true);
    Mfont.setPointSize(16);

    labMoniteur = new QLabel("Moniteur",this);
    labMoniteur->setFont(Mfont);
    labMoniteur->setAlignment(Qt::AlignTop);

    //a enlever par la suite
    labMoniteur->resize(300,200);
}

Moniteur::~Moniteur()
{

}

