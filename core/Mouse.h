#ifndef MOUSE_H
#define MOUSE_H

#include "Drawable.h"

class Drawable;
class Brush;
class Path;

class Mouse: public Drawable
{
public:
    Mouse();
    virtual Path Draw(Brush brush);

};

#endif // MOUSE_H
