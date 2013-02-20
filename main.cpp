#include "mainwindow.h"
#include "ProjectManager.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //int screenWidth, screenHeight;

    QApplication app(argc, argv);

    ProjectManager *chutier = new ProjectManager();
    Project *project1 = chutier->newProject("/home/cecilia/Documents");
    Project *project2 = chutier->newProject("/home/cecilia", "myProject");

    QList<QString> open = chutier->getOpenProjectsList();

    qDebug() << "open list :" << open;

    project1->importVideo("/home/cecilia/Vidéos/bunny.mp4");
    project1->importVideo("/home/cecilia/Vidéos/ludovik.mp4");
    qDebug() << "project 1 :" << project1->getProjectName();
    qDebug() << "project 1 :" << project1->getProjectPath();
    qDebug() << "project 1 :" << project1->getVideoListSize();


    project2->importVideo("/home/cecilia/Vidéos/bunny.mp4");
    qDebug() << "project 2 :" << project2->getProjectName();
    qDebug() << "project 2 :" << project2->getProjectPath();
    qDebug() << "project 2 :" << project2->getVideoListSize();

    chutier->closeAllProjects();
    open = chutier->getOpenProjectsList();
    qDebug() << "open list :" << open;



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
