
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
    QVBoxLayout *layout = new QVBoxLayout(this);
    QPushButton *b = new QPushButton();

    b->setText("neco");
    QPushButton *b2 = new QPushButton();
    b2->setText("neco 2");
    layout->addWidget(b);
    layout->addWidget(b2);

}

MainWindow::~MainWindow()
{
    delete ui;
}


