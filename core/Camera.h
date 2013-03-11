#ifndef CAMERA_H
#define CAMERA_H

#include "Drawable.h"

class Drawable;
class Path;
class Brush;

class Camera: public Drawable
{
public:
    Camera();
    virtual Path Draw(Brush brush);
};

#endif // CAMERA_H
