#ifndef PICTURE_H
#define PICTURE_H

#include <QImage>
#include <QPixmap>
#include <QString>
#include <QColor>
#include <QFont>


class Picture
{
private:
    QString AsciiIm;    //proměná pro uložení onrazku ve formátu ASCII
    QImage im;        //proměná pro uložení obrazku

    QString asciiChar = "  .,:ilwW@@"; //znaky pro ASCII art;
    int ImWidth;
    int ImHeight;
public:
    Picture(QImage im); //konstruktor
    Picture();

    void SetIm(QString path);   //nastavení obrázku

    QPixmap getPixmap();    //vrátí QPiaxmap

    QString getAsciiIm();   //vrátí ascii obrazek

};

#endif // PICTURE_H
