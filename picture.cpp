#include "picture.h"

Picture::Picture(QPicture im)
{
    this->im = im;
}

void Picture::SetIm(QString path){
    this->im.load(path);
}
