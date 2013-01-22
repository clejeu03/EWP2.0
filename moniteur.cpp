#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "moniteur.h"
#include "player/Player.h"

Moniteur::Moniteur(QWidget *parent):QWidget(parent)
{
    QFont Mfont;
    Mfont.setBold(true);
    Mfont.setPointSize(16);

    VideoCapture * capture = new VideoCapture("/home/cecilia/Vidéos/big_buck_bunny.mp4");
    Player *player = new Player(capture);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(player);
    player->show();


    labMoniteur = new QLabel("Moniteur",this);
    labMoniteur->setFont(Mfont);
    labMoniteur->setAlignment(Qt::AlignTop);

}

Moniteur::~Moniteur()
{

}

