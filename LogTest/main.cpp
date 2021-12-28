#include "logwidget.h"
#include <QApplication>
#include <QObject>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogWidget w;
    w.show();
    QTimer timer;
    QObject::connect(&timer,&QTimer::timeout,[]{static int i=0;qDebug()<<"计时器："<<i++;});
    timer.start(1000);
    return a.exec();
}
