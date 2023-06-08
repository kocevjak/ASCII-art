#include "picture.h"

Picture::Picture(QImage im)
{
    this->im = im;
}

Picture::Picture(){}

void Picture::SetIm(QString path){
    this->im.load(path);
    this->scale = 4;
    this->ImWidth = this->im.width()/scale;
    this->ImHeight = this->im.height()/scale;
}

QPixmap Picture::getPixmap(){
    return QPixmap::fromImage(im);
}

QString Picture::getAsciiIm(){
    QString out;
    QColor color;
    double index;
    double charSize = 255/11;
    for (int i = 0; i < this->ImHeight; ++i) {
        for (int j = 0; j < this->ImWidth; ++j) {
            color.setRgb(im.pixel(j*scale,i*scale));
            index = ((color.red()/3 + color.green()/3 + color.blue()/3)-3)/charSize;
            out.push_back(this->asciiChar[(int)(index)]);
            out.push_back(this->asciiChar[(int)(index)]);
        }
        out.push_back("\n");
    }
    //out.setNum(ImWidth);
    return out;
}


int Picture::getWidth(){
    return this->ImWidth;
}

int Picture::getHeight(){
    return this->ImHeight;
}
