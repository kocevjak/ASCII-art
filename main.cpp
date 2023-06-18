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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.showMaximized();
    return a.exec();
}
