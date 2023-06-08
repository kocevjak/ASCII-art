#include "picture.h"

Picture::Picture(QImage im)
{
    this->im = im;
}

Picture::Picture(){}

void Picture::SetIm(QString path){
    this->im.load(path);
    this->ImWidth = this->im.width();
    this->ImHeight = this->im.height();
}

QPixmap Picture::getPixmap(){
    return QPixmap::fromImage(im);
}

QString Picture::getAsciiIm(){
    QColor color(this->im.pixel(0,0));
    return color.name();
}
