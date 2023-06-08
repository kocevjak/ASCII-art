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
    int index;
    double charSize = 255/this->asciiChar.size();
    for (int i = 0; i < this->ImWidth/10; ++i) {
        for (int j = 0; j < this->ImHeight/10; ++j) {
            color.setRgb(im.pixel(i*10,j*10));
            index = color.red()/3 + color.green()/3 + color.blue()/3;
            out.push_back(this->asciiChar[(int)(6)]);
            out.push_back(this->asciiChar[(int)(7)]);
        }
        out.push_back("\n");
    }
    //out.setNum(ImWidth);
    return out;
}
