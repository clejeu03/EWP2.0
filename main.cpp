#include "view/MainWindow.h"

#include <QHBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QTextCodec>
#include <QDebug>
#include "core/Timeline.h"
#include "core/Video.h"

int main(int argc, char *argv[])
{
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

   // int screenWidth, screenHeight;

    QApplication app(argc, argv);

    Video *video1 = new Video("/home/damaris/Vidéos/bunny.mp4");
    Video *video2 = new Video("/home/damaris/Vidéos/ludovik.mp4");

    QMap<int, Video*> sourceMap;
    sourceMap[0]= video1;
    sourceMap[1] = video2;
    Timeline *timeline = new Timeline(sourceMap);

    qDebug() << "__________CREATION__________";
    qDebug() << "drawing status : " << timeline->getDrawingStatus();
    qDebug() << "list size : " << timeline->getVideoList();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();

    //timeline.addVideo(video1);
    //timeline.addVideo(video2);

    qDebug() << "__________ADDING__________";
    qDebug() << "list size : " << timeline->getListSize();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(0)->getCompleteName();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(1)->getCompleteName();

    qDebug() << "__________REMOVING VIDEO1__________";
    timeline->removeVideo(0);
    qDebug() << "list size : " << timeline->getListSize();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();
    qDebug() << "list(0) : " << timeline->getVideoList().value(0)->getCompleteName();
    //qDebug() << "list(1) : " << timeline.getVideoList().value(1)->getCompleteName();

    timeline->addVideo(video1);

     qDebug() << "__________ADDING VIDEO2__________";
     qDebug() << "list size : " << timeline->getListSize();
     qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();
     qDebug() << "list(0) : " << timeline->getVideoList().value(0)->getCompleteName();
     qDebug() << "list(1) : " << timeline->getVideoList().value(1)->getCompleteName();

    timeline->switchVideo(video1, video2);

    qDebug() << "__________MOVING VIDEOS__________";
    qDebug() << "list size : " << timeline->getListSize();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();
    qDebug() << "list(0) : " << timeline->getVideoList().value(0)->getCompleteName();
    qDebug() << "list(1) : " << timeline->getVideoList().value(1)->getCompleteName();

    qDebug() << "__________SETTING REVERSE VIDEO1__________";
    qDebug() << " video 1 : " << video1->getReverse();
    qDebug() << " video 2 : " << video2->getReverse();
    timeline->setReverse(video1);
    qDebug() << "list size : " << timeline->getListSize();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(0)->getCompleteName();
    qDebug() << "adding 2 videos : " << timeline->getVideoList().value(1)->getCompleteName();
    qDebug() << " video 1 : " << video1->getReverse();
    qDebug() << " video 2 : " << video2->getReverse();

    timeline->clear();
    qDebug() << "__________CLEAR__________";
    qDebug() << "list size : " << timeline->getListSize();
    qDebug() << "keys : " << timeline->getVideoList().uniqueKeys();

    MainWindow window;
    window.show();

    return app.exec();

}

