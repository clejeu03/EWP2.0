
#include "Timeline.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QTextCodec>
#include <QDebug>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //int screenWidth, screenHeight;

    QApplication app(argc, argv);

    Timeline timeline;

    Video *video1 = new Video("/home/cecilia/Vidéos/bunny.mp4");
    Video *video2 = new Video("/home/cecilia/Vidéos/ludovik.mp4");
    timeline.addVideo(video1);
    timeline.addVideo(video2);
    qDebug() << "drawing status : " << timeline.getDrawingStatus();

    qDebug() << "adding 2 videos : " << timeline.getVideoList();
    qDebug() << "list size : " << timeline.getListSize();

    timeline.removeVideo(video2);
    qDebug() << "removing video2: " <<  timeline.getVideoList();
    qDebug() << "list size : " << timeline.getListSize();

    timeline.addVideo(video2);
    qDebug() << "adding again video2 : " << timeline.getVideoList();
    qDebug() << "list size : " << timeline.getListSize();

    timeline.moveVideo(video2, 1);
    qDebug() << "moving video2 : " << timeline.getVideoList();
    qDebug() << "list size : " << timeline.getListSize();

    timeline.setReverse(video1);
    qDebug() << "setting reverse on video1 : " << timeline.getVideoList();
    qDebug() << "list size : " << timeline.getListSize();
    qDebug() << " video 1 : " << video1->getReverse();

    timeline.clear();
    qDebug() << "all clear :  " << timeline.getVideoList();
    qDebug() << "list size : " << timeline.getListSize();


    /*mainWindow window;

    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width() -50;
    screenHeight = desktop->height()-50;

    window.setWindowTitle("Titre projet - Electronic Wallpaper 2.0");
    window.setWindowIcon(QIcon("icon.jpg"));
    window.resize(screenWidth, screenHeight);

    window.show();*/

    return app.exec();

}
