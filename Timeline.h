#ifndef TIMELINE_H
#define TIMELINE_H

/*#include "Drawing.h"
#include "Path.h"
#include "PathManager.h"
#include "VideoUtils.h"
#include "Visible.h"
#include "ScriptManager.h"*/

#include "Video.h"
#include "QMapIterator"


class Timeline {


 public:
    Timeline();

    void addVideo(Video* video);
    void removeVideo(Video* video);
    void setDrawingStatus(bool status);
    void setReverse(Video* video); //like a on-off button ; no need to pass a boolean status in argument
    void moveVideo(Video* video, int newPos);
    inline void clear(){m_videoList.clear();}

    int getListSize();
    inline bool getDrawingStatus(){return m_drawingStatus;}
    inline QMap<int, Video*> getVideoList(){return m_videoList;}

private:
    bool m_drawingStatus;
    QMap<int, Video*> m_videoList;

    /*VideoUtils myVideoUtils;
    Drawing &myDrawing;
    Path myPath;
    PathManager myPathManager;
    ScriptManager myScriptManager;*/
};

#endif // Timeline_h
