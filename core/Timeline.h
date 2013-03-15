#ifndef TIMELINE_H
#define TIMELINE_H

/*#include "Drawing.h"
#include "Path.h"
#include "PathManager.h"

#include "Visible.h"
#include "ScriptManager.h"*/

#include "Video.h"
#include "QMap"
#include "Drawable.h"
#include "Path.h"
//#include "VideoUtils.h"


class Timeline {


 public:
    Timeline();
    Timeline(QMap<int, Video*> sourceMap);

    void addVideo(Video* video);
    void removeVideo(Video* video);
    void removeVideo(int index);
    void setDrawingStatus(bool status);
    void setReverse(Video* video); //like a on-off button ; no need to pass a boolean status in argument
    void switchVideo(Video* video, int newPos);
    void switchVideo(int pos, int newPos);
    void switchVideo(Video* source, Video* target);
    /*inline void render(){m_videoUtils.rendering();}*/
    inline void clear(){m_videoList.clear();}

    inline int getListSize(){return m_videoList.size();}
    inline bool getDrawingStatus(){return m_drawingStatus;}
    inline QMap<int, Video*> getVideoList(){return m_videoList;}

private:
    bool m_drawingStatus;
    QMap<int, Video*> m_videoList;//Stocke les vidéos en leur associant un index qui va de 0 à n (pour n+1 vidéos)
    Drawable *drawable;
    QList<Path> m_listPaths;

    /*Drawing &myDrawing;
    VideoUtils m_videoUtils;
    Path myPath;
    PathManager myPathManager;
    ScriptManager myScriptManager;*/
};

#endif // Timeline_h