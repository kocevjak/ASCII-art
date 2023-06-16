
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QFont>
#include <QSpacerItem>
#include <QString>
#include <QFileDialog>
#include <QBoxLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QSlider>
#include <cmath>

#include "picture.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  //konstruktor
    ~MainWindow();  //dedtruktor
    void setLayout();   //funkce pro nastavení layoutu


private slots:
    void on_actionOpen_triggered();     //otevření obrázku

    void on_actionImage_triggered();    //uložení ASCII obrázku jako obrázek

    void on_actionText_triggered();     //uložení ASCII obrázku jako text

    void on_actionboth_triggered();     //uložení původního obrázku a ASCII obrázku do jednoho souboru

    void PictureChange();    //změna jasu obrázku

private:
    Ui::MainWindow *ui;

    Picture* data = new Picture();
    QFont *AsciiFont = new QFont("Monospace");

    //function
    QLabel* setPicJpg();    //funkce vrátí label připravený na náhled obrázku
    QLabel* setPicAscii();  //funkce vrátí label pro ascii obrazek
    void setAsciiFont();    //nastaveví font pro zobrazení ascii obrázku
    void setPictureLayout();

    //message box
    QMessageBox *msg_box = new QMessageBox();

    //widget
    QLabel* pic_jpg;
    QLabel* pic_Ascii;
    QWidget *pic_ascii_w;

    QLabel *Brightness_l;
    QSlider *Brightness;

    QLabel *Contrast_l;
    QSlider *Contrast;

    //event


};

#endif // MAINWINDOW_H
