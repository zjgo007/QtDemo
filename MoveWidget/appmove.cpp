#include "appmove.h"

//AppMove *AppMove::self = 0;
//AppMove *AppMove::Instance()
//{
//    if (!self) {
//        QMutex mutex;
//        QMutexLocker locker(&mutex);
//        if (!self) {
//            self = new AppMove;
//        }
//    }
//    return self;
//}

AppMove::AppMove(QObject *parent) : QObject(parent)
{

}

bool AppMove::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *w = (QWidget *)obj;
    if (!w->property("canMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - w->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            w->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QObject::eventFilter(obj, evt);
}

void AppMove::start()
{
    qApp->installEventFilter(this);
}
