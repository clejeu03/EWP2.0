#ifndef CAMERA_H
#define CAMERA_H

class Drawable;

class Camera: public Drawable
{
public:
    Camera();
    virtual void Draw();
};

#endif // CAMERA_H
