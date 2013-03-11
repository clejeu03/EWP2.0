#ifndef DRAWABLE_H
#define DRAWABLE_H

class Brush;
class Path;

class Drawable {

 public:

    virtual Path Draw(Brush brush)  = 0;
    virtual ~Drawable() { }// virtual destructor for interface
};


#endif // DRAWABLE_H
