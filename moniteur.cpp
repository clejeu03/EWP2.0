#include <opencv2/opencv.hpp>
#include <QFile>
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
    player->resize(200,200);
    player->show();

    /*Setting CSS file*/
    QFile file("../player/playerStyleSheet.css");
    file.open(QFile::ReadOnly);
    QString playerStyleSheet = QLatin1String(file.readAll());
    player->setStyleSheet(playerStyleSheet);

    labMoniteur = new QLabel("Moniteur",this);
    labMoniteur->setFont(Mfont);
    labMoniteur->setAlignment(Qt::AlignTop);

}

Moniteur::~Moniteur()
{

}

