


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(this->ui->widget);


    QLabel *pic_jpg = setPicJpg();

    QLabel *pic_Ascii = setPicAscii();

    this->ui->picture->addSpacing(10);
    this->ui->picture->setAlignment(Qt::AlignTop);

    this->ui->picture->addWidget(pic_jpg);
    this->ui->picture->addWidget(pic_Ascii);

    this->ui->layout->addSpacing(50);
    this->ui->layout->addLayout(this->ui->picture);

    this->ui->widget->setLayout(this->ui->layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLabel* MainWindow::setPicJpg(){
    QPixmap p(700,800);
    QLabel *pic = new QLabel();
    pic->setPixmap(p);
    return pic;
}

QLabel* MainWindow::setPicAscii(){
    QLabel *pic = new QLabel();
    return pic;
}
