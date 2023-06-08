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
    QString out;
    QColor color;
    for (int i = 0; i < this->ImWidth; ++i) {
        for (int j = 0; j < this->ImHeight; ++j) {
            color.setRgb(im.pixel(i,j));

        }
    }
    return color.name();
}
