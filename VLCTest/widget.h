#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_pause_clicked(bool checked);
    void on_pushButton_stop_clicked();

private:
    Ui::Widget *ui;
    VlcInstance *instance;
    VlcMedia *media;
    VlcMediaPlayer *player;

};

#endif // WIDGET_H
