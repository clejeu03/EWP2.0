#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H


#include <qmediaplayer.h>
#include <QtGui/QMovie>
#include <QtWidgets/QWidget>
#include <QtWidgets>
#include <qvideowidget.h>
#include <qvideosurfaceformat.h>

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QSlider;
class QLabel;
QT_END_NAMESPACE

class VideoPlayer : public QWidget
{
    Q_OBJECT
public:
    VideoPlayer(QWidget *parent = 0);
    void setNewMedia(const QString* filename);
    ~VideoPlayer();

public slots:
    void openFile();
    void play();
    void displayTime(int);

private slots:
    void mediaStateChanged(QMediaPlayer::State state);
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);

private:
    QMediaPlayer mediaPlayer;
    QAbstractButton *playButton;
    QSlider *positionSlider;
    QLabel *label;
};

#endif

