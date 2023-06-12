
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
//#include <QFont>
#include <QSpacerItem>
#include <QString>
#include <QFileDialog>

#include "picture.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();  //konstruktor


private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

    //Picture* data = new Picture();
    //QFont *font;

    //function
    QLabel* setPicJpg();    //funkce vrátí label připravený na náhled obrázku
    QLabel* setPicAscii();  //funkce vrátí label pro ascii obrazek

    //layout
    //QHBoxLayout* picture;

    //widget
    QLabel* pic_jpg;
    QLabel* pic_Ascii;
};

#endif // MAINWINDOW_H
