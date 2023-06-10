

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <QImage>
#include <QRgb>
#include <QColor>
#include <QFont>
#include <QFontInfo>
#include <QResizeEvent>
#include <QMainWindow>

#include "mainwindow.h"
#include "picture.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    MainWindow m(&w);
    Picture data;

    w.setWindowTitle("ASCII Art");
    w.setWindowState(Qt::WindowMaximized);


    QVBoxLayout layout;
    QHBoxLayout file;
    //QVBoxLayout setting;
    QHBoxLayout content;

    //tlačítko pro vybrání obrazku
    QPushButton open_foto("open picture");
    open_foto.setFixedWidth(100);

    //tlačítko pro uložení obrázku
    QPushButton save_photo("save picture");
    save_photo.setFixedWidth(100);

    QPixmap pic(600,500);

    //proměná pro náhled obrázku
    QLabel picture_jpg;
    picture_jpg.setStyleSheet("border: 1px solid black");
    //picture_jpg.setFixedSize(w.frameSize());
    //picture_jpg.setFixedWidth(w.width());
    picture_jpg.setMinimumWidth(300);
    picture_jpg.setMinimumHeight(400);
    picture_jpg.setPixmap(pic.scaled(pic.height(),pic.width(), Qt::KeepAspectRatio));
    picture_jpg.setAlignment(Qt::AlignHCenter);

    //proměná pro výsledný obrázek
    QLabel picture_ascii;
    //picture_ascii.setMinimumHeight(300);
    //picture_ascii.setMinimumWidth(400);
    //picture_ascii.setNum(w.width());
    QFont font("Monospace");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    picture_ascii.setFont(font);


    content.addWidget(&picture_jpg);
    content.addWidget(&picture_ascii);


    file.addWidget(&open_foto);
    file.addWidget(&save_photo);
    file.setAlignment(Qt::AlignLeft);

    layout.addLayout(&file);
    layout.addLayout(&content);
    layout.setAlignment(Qt::AlignTop);

    w.setLayout(&layout);





    QObject::connect(&open_foto, &QPushButton::clicked,[&](){
        QString FilePaths = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Image file (*jpg *png");
        if(FilePaths.size() > 0){
            data.SetIm(FilePaths);
            picture_jpg.setPixmap(data.getPixmap().scaledToWidth(picture_ascii.width()));
            font.setPixelSize(picture_jpg.height()/data.getHeight());
            font.setStretch(50);
            picture_ascii.setFont(font);
            picture_ascii.setText(data.getAsciiIm());
        }
    });

    w.showMaximized();
    m.show();
    picture_jpg.setFixedWidth(w.width()/2);

    return a.exec();
}
