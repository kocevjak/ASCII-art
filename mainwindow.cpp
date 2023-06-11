


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

    picture->setAlignment(Qt::AlignTop);
    picture->addSpacing(10);
    picture->addWidget(pic_jpg);
    picture->addSpacing(5);
    picture->addWidget(pic_Ascii);
    picture->addSpacing(10);

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
    pic->setAlignment(Qt::AlignHCenter);
    pic->setPixmap(p);
    pic->setStyleSheet("border: 1px solid black");
    //pic->setFixedWidth(this->ui->widget->width();
    return pic;
}

QLabel* MainWindow::setPicAscii(){
    QLabel *pic = new QLabel();
    pic->setStyleSheet("border: 1px solid black");
    return pic;
}

void MainWindow::on_actionOpen_triggered()
{
    QString FilePath = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Image file (*jpg *png");
    if(FilePath.size() > 0){
        data.SetIm(FilePath);
        picture_jpg.setPixmap(data.getPixmap().scaledToWidth(picture_ascii.width()));
        font.setPixelSize(picture_jpg.height()/data.getHeight());
        font.setStretch(50);
        picture_ascii.setFont(font);
        picture_ascii.setText(data.getAsciiIm());
    }
}

