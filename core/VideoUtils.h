#ifndef VIDEOUTILS_H
#define VIDEOUTILS_H

#include "Path.h"

class VideoUtils
{
public:
    VideoUtils();
    static void extract(Video *video, int input, int output);
    static void merge();
    static void rendering(Path *path);
    static void exportRendering();
};

#endif // VIDEOUTILS_H
