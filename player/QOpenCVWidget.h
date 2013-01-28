#ifndef QOPENCVWIDGET_H
#define QOPENCVWIDGET_H

#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QImage>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

class QOpenCVWidget : public QWidget{

private:
    QLabel *imagelabel;
    QVBoxLayout *layout;
    QHBoxLayout *hLayout;
    QImage image;

public:
    QOpenCVWidget(QWidget *parent = 0);
    void putImage(IplImage *cvimage);
    IplImage* qImage2IplImage(const QImage& qImage);//Converti QImage en IplImage
    QImage IplImage2QImage(const IplImage *iplImage);//Converti IplImage en QImage
};



#endif // QOPENCVWIDGET_H
