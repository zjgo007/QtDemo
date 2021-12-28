#ifndef APPMOVE_H
#define APPMOVE_H

#include <QObject>
#include <QMutex>
#include <QEvent>
#include <QWidget>
#include <QApplication>
#include <QMouseEvent>
#include <QtDebug>

class AppMove:public QObject
{
public:
public:
//    static AppMove *Instance();
    explicit AppMove(QObject *parent = 0);

    void start();

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

//private:
//    static AppMove *self;
};

#endif // APPMOVE_H
