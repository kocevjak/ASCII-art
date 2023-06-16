#include "picture.h"



Picture::Picture(QImage im)
{
    this->im = im;
    this->imOriginal = im;
}

Picture::Picture(){
    this->imScale.load("");
    this->AsciiIm = "";
    this->imSmall.load("");
    this->im.load("");
    this->imOriginal.load("");
    this->ImWidth = -1;
    this->ImHeight = -1;
}

Picture::~Picture(){

}

void Picture::SetIm(QString path){
    this->im.load(path);
    this->im = addBackground(this->im);

    this->imOriginal = this->im;
    this->imSmall = this->im;

    this->imSmall = this->imSmall.scaledToHeight(190);

    this->ImWidth = this->imSmall.width();
    this->ImHeight = this->imSmall.height();
    this->isSetIm = true;
}

QPixmap Picture::getPixmap(){
    return QPixmap::fromImage(im);
}

QString Picture::getAsciiIm(){
    QString out;
    QColor color;
    double index;
    double charSize = 255/((double)asciiChar.size());
    for (int i = 0; i < this->ImHeight; ++i) {
        for (int j = 0; j < this->ImWidth; ++j) {
            color.setRgb(imSmall.pixel(j,i));
            index = (255-(color.red()/3 + color.green()/3 + color.blue()/3)-3)/charSize;
            out.push_back(this->asciiChar.at((int)(index)));
            out.push_back(this->asciiChar.at((int)(index)));
            out.push_back(this->asciiChar.at((int)(index)));
        }
        out.push_back("\n");
    }
    return out;
}

QPixmap Picture::getSmallPixmap(){
    return QPixmap::fromImage(this->imSmall);
}

QImage Picture::addBackground(const QImage &im){
    QImage resultImage(im.size(), QImage::Format_ARGB32);
    resultImage.fill(Qt::white);

    QPainter painter(&resultImage);

    painter.drawImage(0, 0, im);

    painter.end();

    return resultImage;
}

QPixmap Picture::getScalePixmap(){
    return QPixmap::fromImage(this->imScale);
}

void Picture::setScalePixmap(int width, int height){
    this->scaleWidth = width;
    this->scaleHeight = height;
    this->imScale = im.scaled(width,height,Qt::KeepAspectRatio);
}

int Picture::getWidth(){
    return this->ImWidth;
}

int Picture::getHeight(){
    return this->ImHeight;
}

void Picture::setContrast(int value){
    //this->im.load("D:\skola\CVUT\skola\2_sem\programovani_C++\du\hw05\frames\frame_01.png");
}

void Picture::setBrightness(int value){

    this->im = this->imOriginal+value;
    updateIm();
}

void Picture::updateIm(){
    this->imSmall = this->im;
    this->imSmall = this->imSmall.scaledToHeight(190);
    getAsciiIm();

    this->imSmall = this->im;
    setScalePixmap(this->scaleWidth,this->scaleHeight);
}

//operator
QImage operator*(const QImage& imag,const int v){
    QImage out = imag;
    /*QRgb color;
    out = imag;
    for (int i = 0; i < imag.height(); ++i) {
        for (int j = 0; j < imag.width(); ++j) {
            color = imag.pixel(j,i)*Picture::parseInt(v);
            out.setPixelColor(j,i,color);
        }
    }*/
    return out;
}

QImage operator+(QImage imag,const int v){
    QImage out = imag;

    for (int i = 0; i < imag.height(); ++i) {
        for (int j = 0; j < imag.width(); ++j) {
            out.setPixelColor(j,i,(imag.pixelColor(j,i)+v));
        }
    }

    return out;
}

QColor operator+(const QColor col,const int v){
    QColor out;
    out.setRed(parseInt(col.red()+v));
    out.setGreen(parseInt(col.green()+v));
    out.setBlue(parseInt(col.blue()+v));

    return out;
}

int parseInt(int v){
    if(v > 255){
        v = 255;
    }
    else if(v < 0){
        v = 0;
    }
    //qDebug() << v << "\n";
    return v;
}
