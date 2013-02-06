#include "editor.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

Editor::Editor(QObject *parent) :
    QObject(parent)
{
}

Editor::Editor(QString filepath, int value1, int value2, QObject *parent):QObject(parent){
    m_filepath = filepath;
    m_in = value1;
    m_out = value2;
    qDebug() << "file1 :" << m_filepath << m_in << m_out ;
}
void Editor::VideoSplit(Editor* editor){
    qDebug() << "editing ...";

    CvCapture* capture = cvCreateFileCapture(editor->m_filepath.toLatin1().data());
    IplImage* frame = cvQueryFrame(capture);
    int fps = cvGetCaptureProperty(capture,CV_CAP_PROP_FPS);
    CvSize size = cvSize(
        (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH),
        (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT)
    );
    CvVideoWriter *writer = cvCreateVideoWriter("../EWP2.0/tmp/tmp.avi",CV_FOURCC('M','J','P','G'),fps,size);
    for(int i=(editor->m_in); i < (editor->m_out); ++i){
        cvWriteFrame( writer, frame);
    }
    cvReleaseVideoWriter( &writer );
    cvReleaseCapture( &capture );
}
