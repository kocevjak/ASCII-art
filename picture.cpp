#include "picture.h"

Picture::Picture(QImage im)
{
    this->im = im;
}

void Picture::SetIm(QString path){
    this->im.load(path);
}

QPixmap Picture::getPixmap(){
    return QPixmap::fromImage(im);
}
