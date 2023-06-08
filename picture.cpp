#include "picture.h"

Picture::Picture(QImage im)
{
    this->im = im;
}

Picture::Picture(){}

void Picture::SetIm(QString path){
    this->imFull.load(path);
    this->imFull = addBackground(this->im);

    this->im = this->imFull.scaledToHeight(180);
    this->ImWidth = this->im.width();
    this->ImHeight = this->im.height();
}

QPixmap Picture::getPixmap(){
    return QPixmap::fromImage(im);
}

QString Picture::getAsciiIm(){
    QString out;
    QColor color;
    double index;
    double charSize = 255/asciiChar.size();
    for (int i = 0; i < this->ImHeight; ++i) {
        for (int j = 0; j < this->ImWidth; ++j) {
            color.setRgb(im.pixel(j,i));
            index = (255-(color.red()/3 + color.green()/3 + color.blue()/3)-3)/charSize;
            out.push_back(this->asciiChar[(int)(index)]);
            out.push_back(this->asciiChar[(int)(index)]);
        }
        out.push_back("\n");
    }
    //out.setNum(ImWidth);
    return out;
}

QImage Picture::addBackground(const QImage &im){
    QImage resultImage(im.size(), QImage::Format_ARGB32);
    resultImage.fill(Qt::white);

    QPainter painter(&resultImage);

    // Vykreslení původního PNG obrázku s průhledností
    painter.drawImage(0, 0, im);


    painter.end();

    return resultImage;
}

int Picture::getWidth(){
    return this->ImWidth;
}

int Picture::getHeight(){
    return this->ImHeight;
}
