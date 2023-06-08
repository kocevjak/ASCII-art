#ifndef PICTURE_H
#define PICTURE_H

#include <QPicture>
#include <QPixmap>
#include <QString>


class Picture
{
private:
    QString AsciiIm;    //proměná pro uložení onrazku ve formátu ASCII
    QPicture im;        //proměná pro uložení obrazku

    QString asciiChars = "  .,:ilwW@@"; //znaky pro ASCII art;
public:
    Picture(QPicture im); //konstruktor
    Picture();

    void SetIm(QString path);   //nastavení obrázku

    QPixmap getPixmap();    //vrátí QPiaxmap

    QString getAsciiIm();   //vrátí ascii obrazek

};

#endif // PICTURE_H
