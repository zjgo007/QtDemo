#include "widget.h"
#include "appmove.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppMove move;
    move.start();

    Widget w;
    w.show();

    return a.exec();
}
