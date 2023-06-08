#ifndef PICTURE_H
#define PICTURE_H

#include <QPicture>
#include <QPixmap>
#include <QString>


class picture
{
private:
    QString AsciiIm;    //proměná pro uložení onrazku ve formátu ASCII
public:
    picture(QPicture im); //konstruktor

    QPixmap getPixmap();    //vrátí QPiaxmap

    QString getAsciiIm();   //vrátí ascii obrazek

    QPicture im;//proměná pro uložení obrazku
};

#endif // PICTURE_H
