


#include "mainwindow.h"
//#include "picture.h"
#include "ui_mainwindow.h"

//private function
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    pic_ascii_w = new QWidget();
    pic_ascii_w->setStyleSheet("border: 1px solid black");

    pic_jpg = setPicJpg();
    pic_Ascii = setPicAscii();

    this->pic_ascii_w->setMinimumSize(this->size()/2);
    this->pic_ascii_w->setMaximumSize(this->size());
    this->pic_jpg->setMinimumSize(this->size()/2);
    this->pic_jpg->setMaximumSize(this->size());

    //set Brightness
    this->Brightness_l = new QLabel();
    this->Brightness_l->setText("Brightness");
    this->Brightness = new QSlider(Qt::Horizontal);
    this->Brightness->setTickPosition(QSlider::TicksAbove);
    this->Brightness->setMinimum(0);
    this->Brightness->setMaximum(100);
    this->Brightness->setValue(50);

    //set contrast
    this->Contrast_l = new QLabel();
    this->Contrast_l->setText("Contrast");
    this->Contrast = new QSlider(Qt::Horizontal);
    this->Contrast->setTickPosition(QSlider::TicksAbove);
    this->Contrast->setMinimum(0);
    this->Contrast->setMaximum(100);
    this->Contrast->setValue(50);

    this->setLayout();  //nastavení layoutu
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLayout(){
    //layout
    QHBoxLayout *picture = new QHBoxLayout();

    QVBoxLayout *controls = new QVBoxLayout();

    this->setCentralWidget(this->ui->widget);   //nastavení centralWidget

    //nastavení picture
    picture->setAlignment(Qt::AlignTop);
    picture->addSpacing(10);
    picture->addWidget(pic_jpg);
    picture->addSpacing(5);
    picture->addWidget(pic_ascii_w);
    picture->addSpacing(10);

    controls->addWidget(this->Brightness_l);
    controls->addWidget(this->Brightness);
    controls->addWidget(this->Contrast_l);
    controls->addWidget(this->Contrast);
    controls->setAlignment(Qt::AlignTop);

    this->layout()->setAlignment(Qt::AlignTop);

    this->ui->layout->addSpacing(10);
    this->ui->layout->addLayout(picture);

    this->ui->layout->addLayout(controls);

    this->ui->widget->setLayout(this->ui->layout);
}

//public function
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
    QLabel *pic = new QLabel(this->pic_ascii_w);
    pic->setStyleSheet("border: 1px solid black");
    pic->setFixedSize(0,0);
    //pic->setAlignment(Qt::AlignHCenter);
    return pic;
}

//private slots
void MainWindow::setAsciiFont(){

    this->AsciiFont->setPixelSize((int)((double)this->pic_ascii_w->height()/(double)data->getSmallPixmap().height()));
    this->AsciiFont->setStretch(70);
    this->AsciiFont->setStyleHint(QFont::Monospace);
    //this->AsciiFont->setFixedPitch(true);
}

void MainWindow::on_actionOpen_triggered()
{
    QString FilePath = QFileDialog::getOpenFileName(nullptr, tr("Open Image"), "", tr("Image file (*.jpg *.png)"));
    if(FilePath.size() > 0){
        this->data->SetIm(FilePath);
        setPictureLayout();
    }
}

void MainWindow::setPictureLayout(){
    data->setScalePixmap(this->pic_jpg->width(),this->pic_jpg->height());
    this->pic_jpg->setPixmap(data->getScalePixmap());

    setAsciiFont();
    this->pic_Ascii->setFont(*this->AsciiFont);
    this->pic_Ascii->setText(this->data->getAsciiIm());
    this->pic_Ascii->setFixedHeight(this->AsciiFont->pixelSize()*data->getSmallPixmap().height());
    this->pic_Ascii->setFixedWidth(this->AsciiFont->pixelSize()*data->getSmallPixmap().width()+5);
    //this->pic_ascii_w->setFixedSize(this->pic_Ascii->size());


    if(((this->AsciiFont->pixelSize())*(data->getSmallPixmap().height())) >= (this->pic_jpg->height())){
        //this->pic_Ascii->setFixedHeight(this->AsciiFont->pixelSize()*data->getSmallPixmap().height());
        //this->pic_ascii_w->setFixedHeight(this->AsciiFont->pixelSize()*data->getSmallPixmap().height());
        //this->pic_Ascii->setFixedWidth(3*this->AsciiFont->pixelSize()*data->getSmallPixmap().width());
    }
}

void MainWindow::on_actionImage_triggered()
{
    QPixmap pic;

    if(data->isSetIm){
        pic = this->pic_Ascii->grab();
        QString path = QFileDialog::getSaveFileName(nullptr,tr("save file"),
                                                    "ASCII art",
                                                    "jpg (*.jpg);"
                                                    ";png (*.png);");
        if(!pic.save(path)){
            this->msg_box->critical(this,"Error","error with save");
        }
    }
    else{
        this->msg_box->critical(this,"Error","not open picture");
    }
}

void MainWindow::on_actionText_triggered()
{
    if(data->isSetIm){
        QString path = QFileDialog::getSaveFileName(nullptr,tr("save file"),
                                                    "ASCII art",
                                                    "txt (*.txt)");
        QFile file(path);
        QTextStream out(&file);
        if(file.open(QIODevice::WriteOnly)){
            out << this->pic_Ascii->text();
            file.close();
        }
        else {
            this->msg_box->critical(this,"Error","not saved");
        }
    }
    else{
        this->msg_box->critical(this,"Error","not open picture");
    }
}

void MainWindow::on_actionboth_triggered()
{
    this->msg_box->information(this,"error","tato funkce zatím není přístupná");
}
