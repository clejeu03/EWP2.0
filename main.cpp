#include "mainwindow.h"
#include "Video.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //int screenWidth, screenHeight;

    QApplication app(argc, argv);

    Video *video = new Video("/home/cecilia/Vidéos/bunny.mp4");

    QFileInfo info("/home/cecilia/Vidéos/bunny.mp4");

    QString name = video->getName();
    QString completeName = video->getCompleteName();
    QString format = video->getFormat();
    QString path = video->getPath();

    double weight = video->getWeight();
    double roundWeight = video->getRoundWeight();
    bool reverse = video->getReverse();
    QString script = video->getScript();
    bool timeline = video->getTimelinePresence();

    qDebug() << "exists :" << info.exists();
    qDebug() << "name :" << name;
    qDebug() << "CompleteName :" << completeName;
    qDebug() << "format :" << format;
    qDebug() << "path : " << path;
    qDebug() << "weight :" << weight;
    qDebug() << "roundWeight :" << roundWeight;
    qDebug() << "reverse :" << reverse;
    qDebug() << "script :" << script ;
    qDebug() << "timeline :" << timeline;


   /* mainWindow window;

    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width() -50;
    screenHeight = desktop->height()-50;

    window.setWindowTitle("Titre projet - Electronic Wallpaper 2.0");
    window.setWindowIcon(QIcon("icon.jpg"));
    window.resize(screenWidth, screenHeight);

    window.show();*/

    return app.exec();

}
