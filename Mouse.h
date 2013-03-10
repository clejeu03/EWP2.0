#ifndef MOUSE_H
#define MOUSE_H

class Drawable;

class Mouse: public Drawable
{
public:
    Mouse();
    virtual void Draw();
};

#endif // MOUSE_H
