


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(this->ui->widget);

    QHBoxLayout *picture = new QHBoxLayout();



    QLabel *pic_jpg = setPicJpg();

    QLabel *pic_Ascii = setPicAscii();

    picture->addSpacing(10);
    picture->setAlignment(Qt::AlignTop);

    picture->addWidget(pic_jpg);
    picture->addWidget(pic_Ascii);

    this->ui->layout->addSpacing(10);
    this->ui->layout->addLayout(picture);

    this->ui->widget->setLayout(this->ui->layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLabel* MainWindow::setPicJpg(){
    QPixmap p(800,600);
    QLabel *pic = new QLabel();
    pic->setPixmap(p);
    return pic;
}

QLabel* MainWindow::setPicAscii(){
    QLabel *pic = new QLabel();
    return pic;
}
