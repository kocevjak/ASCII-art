#ifndef PICTURE_H
#define PICTURE_H

#include <QImage>
#include <QPixmap>
#include <QString>
#include <QColor>
#include <QFont>
#include <QLabel>
#include <QPainter>
#include <QChar>

class Picture
{
private:
    QString AsciiIm;    //proměná pro uložení obrazku ve formátu ASCII
    QImage imSmall;          //proměná pro uložení zmenšeného obrazku k zobrazení do ASCII
    QImage im;      //proměná pro uložení obrázku v plné velikosti
    QImage imScale;     //proměná pro náhled obrázku

    QString asciiChar = " `'.,^:;Il!i~+_-?][}{1)(|/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"; //znaky pro ASCII art;
    int ImWidth;
    int ImHeight;

    QImage addBackground(const QImage &im);   //funkce slouží k přidání pozadí například do PNG obrázku
public:
    Picture(QImage im); //konstruktor
    Picture();
    ~Picture();

    void SetIm(QString path);   //nastavení obrázku

    QPixmap getPixmap();    //vrátí QPiaxmap

    QString getAsciiIm();   //vrátí ascii obrazek

    QPixmap getScalePixmap();   //vrátí zmenšený obrazek
    void setScalePixmap(int width,int height);  //nastaveí zmenšený obrázek

    QPixmap getSmallPixmap();

    int getWidth();
    int getHeight();

    bool isSetIm = false;

};

#endif // PICTURE_H
