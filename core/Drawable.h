#ifndef DRAWABLE_H
#define DRAWABLE_H

class Brush;

class Drawable {

 public:

    virtual void Draw(Brush brush)  = 0;
    virtual ~Drawable() { }// virtual destructor for interface
};


#endif // DRAWABLE_H
