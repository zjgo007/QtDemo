#include "widget.h"
#include <QApplication>
#include <VLCQtCore/Common.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VlcCommon::setPluginPath( "E:/VLC/VLC/bin/plugins");//添加插件所处路径
    Widget w;
    w.show();
    return a.exec();
}
