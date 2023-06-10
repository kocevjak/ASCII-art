
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(this->ui->widget);
    this->ui->widget->setLayout(this->ui->layout);

    QPushButton *b = new QPushButton(this);
    b->setText("neco");
    QPushButton *b2 = new QPushButton(this);
    b2->setText("neco 2");
    ui->layout->addWidget(b);
    ui->layout->addWidget(b2);
}

MainWindow::~MainWindow()
{
    delete ui;
}



