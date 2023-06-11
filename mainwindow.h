
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



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();  //konstruktor


private:
    Ui::MainWindow *ui;
    QSpacerItem *space = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);

    QLabel* setPicJpg();    //funkce vrátí label připravený na náhled obrázku
    QLabel* setPicAscii();  //funkce vrátí label pro ascii obrazek
};

#endif // MAINWINDOW_H
