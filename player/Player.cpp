#include "Player.h"


Player::Player(VideoCapture * capture, QWidget *parent) : QWidget(parent){
    assert(capture);
    Mat video;
    capture->read(video);

    initPlayer(capture);
}

void Player::initPlayer(VideoCapture *video){
    capture = video;
    playStatus = false;
    layout = new QVBoxLayout;
    cvwidget = new QOpenCVWidget(this);


    /*Time initialization*/
    fps = video->get(CV_CAP_PROP_FPS);
    int total_frame = capture->get(CV_CAP_PROP_FRAME_COUNT);
    QTime originTime(0,0,0);
    duration = originTime.addSecs(qRound(total_frame/fps));
std::cout<<"bla"<<std::endl;
    /*Drawing the player*/
    layout->addWidget(cvwidget);
    initSlider();
    QPushButton *playButton = new QPushButton();
    playButton->setFixedWidth(30);
    layout->addWidget(playButton);
    label = new QLabel();
    displayTime(0);
    layout->addWidget(label);

    /*Displaying the first frame to initialize*/
    Mat imgMat;
    capture->read(imgMat);
    IplImage img = imgMat;
    cvwidget->putImage(&img);

    setLayout(layout);

    resize(500, 400);

    /*Connection of the play button*/
    QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(setPlayStatus()));
}

void Player::timerEvent(QTimerEvent*){
    display();
}

void Player::initSlider(){
    /*Creation of the slider*/
     slider = new QSlider(Qt::Horizontal, this);

     int total_frame = capture->get(CV_CAP_PROP_FRAME_COUNT);
     slider->setRange(0, qRound(total_frame/fps));//We could have used setRange(0, duration) but it's complex to convert QTime into int.
     slider->setValue(0);

     /*Drawing*/
     layout->addWidget(slider);
     setLayout(layout);

     /*Connecting the slider actions with player functions*/
     QObject::connect(slider, SIGNAL(valueChanged(int)),this, SLOT(displayTime(int)));
     QObject::connect(slider, SIGNAL(sliderMoved(int)),this, SLOT(tracking(int)));
     QObject::connect(slider, SIGNAL(sliderPressed()),this, SLOT(pause()));
     QObject::connect(slider, SIGNAL(sliderReleased()),this, SLOT(play()));
}

void Player::displayTime(int value){
    /*Creating time references*/
    QTime originTime(0,0,0);
    QTime hour(1,0,0);

    QTime current_time = originTime.addSecs(value);

    /*Display time format according to the video duration : "mm:ss"  or  "hh:mm:ss" */
    if(duration < hour ){
        label->setText(current_time.toString("mm:ss")+" / "+duration.toString("mm:ss"));
    }else{
        label->setText(current_time.toString()+" / "+duration.toString());
    }
}

/*This function display the frames into the widget Player and
increment the slider change of value according to the fps*/
void Player::display(){
    Mat imgMat;
    capture->read(imgMat);
    IplImage img = imgMat;
    cvwidget->putImage(&img);
    int count = capture->get(CV_CAP_PROP_POS_FRAMES);
    if(count%fps == 0){//Increments time value in secondes every 24 frames if fps=24 for example
        int current_pos = slider->value();
        slider->setValue(++current_pos);
    }
}

/*Called when the user act on the trackbar, and refresh display of frames
  following the new slider value*/
void Player::tracking(int pos){
    int current_pos = capture->get(CV_CAP_PROP_POS_MSEC);
    if(pos > current_pos +2 || pos < current_pos -2){
        capture->set(CV_CAP_PROP_POS_MSEC, pos*1000);

    }
}

void Player::setPlayStatus(){
    switch(playStatus){
    case true:
        pause();
        break;
    case false:
        play();
        break;
    default:
        break;
    }
}

void Player::pause(){
    playStatus = false;
    killTimer(timerId);
}

void Player::play(){
    playStatus = true;
    timerId = startTimer(41.667);
}
