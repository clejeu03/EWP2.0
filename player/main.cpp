#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <assert.h>
#include <QApplication>
#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
#include "Player.h"


int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    VideoCapture * capture = new VideoCapture("/home/cecilia/Vidéos/big_buck_bunny.mp4");
    Player *player = new Player(capture);

    player->setWindowTitle("Monitor");
    //player->setWindowFlags(Qt::Tool);
    player->show();

    /*Setting CSS file*/
    QFile file("../player/playerStyleSheet.css");
    file.open(QFile::ReadOnly);
    QString playerStyleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(playerStyleSheet);

    return app.exec();
}
