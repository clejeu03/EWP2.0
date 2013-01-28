#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    int screenWidth, screenHeight;

    QApplication app(argc, argv);
    mainWindow window;

    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width() -50;
    screenHeight = desktop->height()-50;

    window.setWindowTitle("Titre projet - Electronic Wallpaper 2.0");
    window.setWindowIcon(QIcon("icon.jpg"));
    window.resize(screenWidth, screenHeight);

    window.show();

    return app.exec();

}
