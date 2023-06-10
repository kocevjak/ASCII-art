


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(this->ui->widget);


    QLabel *pic_jpg = setPicJpg();

    this->ui->picture->addWidget(pic_jpg);

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


