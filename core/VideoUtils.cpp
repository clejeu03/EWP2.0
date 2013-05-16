#include "VideoUtils.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cmath>

VideoUtils::VideoUtils(){

}

/*=========TO DO ============*/

//This function extract pieces of video
void VideoUtils::extract(Video *video, int input, int output){
        /*
        CvCapture* capture = cvCreateFileCapture(video->getPath().toLocal8Bit().data());
        IplImage* frame = cvQueryFrame(capture);
        int fps = cvGetCaptureProperty(capture,CV_CAP_PROP_FPS);
        CvSize size = cvSize(
            (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH),
            (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT)
        );
        qDebug() << "size :" << (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH) << (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
        CvVideoWriter *writer = cvCreateVideoWriter("../EWP2.0/tmp/tmp.avi",CV_FOURCC('M','J','P','G'),fps,size);
        for(int i=(input); i < (output); ++i){
            cvWriteFrame( writer, frame);
        }
        cvReleaseVideoWriter( &writer );
        cvReleaseCapture( &capture );
        */
    //Convert in/out (percentage) in real video frame
}

void VideoUtils::merge(){

}

//Mix video pieces together
void VideoUtils::rendering(Path * path){
    /*
    QMapIterator<Video*, QPair<int, int> > i(path->getSequences());
    Size maxSize(0,0);

    QList<IplImage*> *frames = new QList<IplImage*>();

    //Parcourt les vidéos et stocke les frames dans Vector frame
    while(i.hasNext()){
        qDebug() << "plop";
        Video* video = i.key();
        int in = i.value().first, out = i.value().second;

        CvCapture* capture = cvCreateFileCapture(video->getPath().toLocal8Bit().data());

        //Positionne la vidéo au bon endroit
        int posFrameStart = cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_COUNT)/100. * in;
        int posFrameEnd = cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_COUNT)/100. * out;
        qDebug() << "start:" << posFrameStart << " end:" << posFrameEnd;
        cvSetCaptureProperty(capture,CV_CAP_PROP_POS_FRAMES, posFrameStart);

        Size size;
        size.width = cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH);
        size.height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
        if(maxSize.height < size.height) maxSize.height = size.height;
        if(maxSize.width < size.width) maxSize.width = size.width;

        IplImage *currentFrame;

        //capture->set(CV_CAP_PROP_POS_MSEC, 10000);
        do{

            cvWaitKey(42);
            currentFrame = cvQueryFrame(capture);
            frames->append(currentFrame);

        }while(cvGetCaptureProperty(capture,CV_CAP_PROP_POS_FRAMES) < posFrameEnd );
       // delete capture;
        qDebug() << "Frames size :" << frames->size();
        cvReleaseCapture(&capture);
        delete video;
        i.next();
    }
    //Ecrit le Vector frame dans un fichier pour obtenir le résultat final
    CvSize size1 = cvSize(maxSize.width, maxSize.height);
     //VideoWriter* result = new VideoWriter("../EWP2.0/tmp/tmp.mpeg",CV_FOURCC('F','M','P','4'),24,maxSize);
    CvVideoWriter* result = cvCreateVideoWriter("../EWP2.0/tmp/tmp.avi",CV_FOURCC('M','J','P','G'),24,size1);

    for(int i=0; i<frames->size();++i){
         qDebug() << "Boucle" << i;
         cvWriteFrame(result,frames->at(i));
    }
    /*
    for(Vector<IplImage>::iterator iter=frames.begin(); iter!=frames.end();++iter){
        cvWriteFrame(result,iter);
    }
     *for(int i = 0; i < frames.size(); i++){
        qDebug() << "Boucle" << i;
        cvWriteFrame(result,&(frames[i]));
    }

    cvReleaseVideoWriter(&result);
    */


    if(!path->getSequences().isEmpty()){
        int fps = 24;
        CvSize size = cvSize(600, 400);
        CvVideoWriter *writer = cvCreateVideoWriter("../EWP2.0/tmp/tmp.avi",CV_FOURCC('M','J','P','G'),fps,size);
        CvCapture *capture;

        //For each video, extract then rewrite
        for(int k=0; k<path->getSequences().size(); ++k){
            qDebug() << "Nouvelle Video !";
            qDebug() << "valeurs : "<< path->getSequences().value(path->getSequences().keys().at(0)).first << path->getSequences().value(path->getSequences().keys().at(0)).second;
            Video* video = path->getSequences().keys().at(k);

            capture = cvCreateFileCapture(video->getPath().toLocal8Bit().data());

            int input = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT)/100 * path->getSequences().value(video).first;
            int output = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT)/100 * path->getSequences().value(video).second;

            IplImage* frame;
            /*int fps = cvGetCaptureProperty(capture,CV_CAP_PROP_FPS);
            CvSize size = cvSize(
                (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH),
                (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT)
            );*/

            cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, input);
            for(int i=(input); i < (output); ++i){
                qDebug() << i ;
                frame = cvQueryFrame(capture);
                cvWriteFrame( writer, frame);
            }
       }
       cvReleaseVideoWriter( &writer );
       cvReleaseCapture( &capture );
    }
}


//Save the rendering video
void VideoUtils::exportRendering(){

}
