#ifndef PLAYER_H
#define PLAYER_H

#include <QPushButton>
#include <QLabel>
#include <QTime>
#include <QSlider>
#include <QWidget>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>




using namespace cv;

class Player: public QWidget{

    Q_OBJECT
private :
    QSlider *slider;
    QOpenCVWidget *cvwidget;
    VideoCapture *capture;
    QVBoxLayout *layout;
    QLabel *label;
    bool playStatus;
    int fps;
    QTime duration;
    int timerId;

private slots:
    void displayTime(int);
    void setPlayStatus();
    void tracking(int);
    void play();
    void pause();

public:
    Player(VideoCapture * capture, QWidget *parent = 0);
    ~Player(){
        delete capture;
    }
    void initPlayer(VideoCapture *video);
    void timerEvent(QTimerEvent*);
    void initSlider();
    bool getPlayStatus(){return playStatus;}
    void display();

};

#endif // PLAYER_H
