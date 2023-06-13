


#include "mainwindow.h"
//#include "picture.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setCentralWidget(this->ui->widget);

    //QLabel *pic_jpg;
    //QLabel *pic_Ascii;

    QHBoxLayout *picture = new QHBoxLayout();
    //this->picture->setAlignment()

    pic_jpg = setPicJpg();

    pic_Ascii = setPicAscii();

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
    //pic->setAlignment(Qt::AlignHCenter);
    return pic;
}

void MainWindow::setAsciiFont(){
    this->AsciiFont->setPixelSize(this->pic_jpg->height()/data->getHeight());
    this->AsciiFont->setStretch(50);
    this->AsciiFont->setStyleHint(QFont::Monospace);
    this->AsciiFont->setFixedPitch(true);
}

void MainWindow::on_actionOpen_triggered()
{
    QString FilePath = QFileDialog::getOpenFileName(nullptr, tr("Open Image"), "", tr("Image file (*.jpg *.png)"));
    if(FilePath.size() > 0){
        this->data->SetIm(FilePath);
        this->pic_jpg->setPixmap(this->data->getPixmap());
        setAsciiFont();
        this->pic_Ascii->setFont(*this->AsciiFont);
        this->pic_Ascii->setText(this->data->getAsciiIm());
    }
}

void MainWindow::on_actionImage_triggered()
{
    QPixmap pic;
    pic = this->pic_Ascii->grab();
    QString path = QFileDialog::getSaveFileName(nullptr,tr("save file"),"");
    pic.save(path);
}

