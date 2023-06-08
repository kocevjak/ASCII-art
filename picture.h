#ifndef PICTURE_H
#define PICTURE_H

#include <QPicture>
#include <QPixmap>
#include <QString>


class picture
{
private:
    QString AsciiIm;    //proměná pro uložení onrazku ve formátu ASCII
    QPicture im;        //proměná pro uložení obrazku

    QString asciiChars = "  .,:ilwW@@"; //znaky pro ASCII art;
public:
    picture(QPicture im); //konstruktor

    QPixmap getPixmap();    //vrátí QPiaxmap

    QString getAsciiIm();   //vrátí ascii obrazek

};

#endif // PICTURE_H
