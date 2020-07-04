#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 400);

    QPixmap pixmap(":/res/1.jpg");
    pixmap = pixmap.scaled(400, 400);

    old_label = new QLabel(this);
    old_label->setGeometry(0, 0, 400, 400);
    old_label->setPixmap(pixmap);


    GaussBlur *blur = new GaussBlur(10, 5.0);

    //QPixmap转化为image之后进调用BlurImage()进行处理
    QImage newImage = blur->StartGauss(pixmap.toImage());

    QPixmap newPixmap;
    newPixmap.convertFromImage(newImage);

    QLabel *new_label = new QLabel(this);
    new_label->setGeometry(400, 0, 400, 400);
    new_label->setPixmap(newPixmap);
}

MainWindow::~MainWindow()
{

}
