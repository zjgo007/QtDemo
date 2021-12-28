#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    instance = new VlcInstance(VlcCommon::args(), this);
    player = new VlcMediaPlayer(instance);
    player->setVideoWidget(ui->VlcWidget);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_start_clicked()
{
    QString url =
            QInputDialog::getText(this, tr("打开网络流"), tr("网络流地址"));

    if (!url.isEmpty()){
        media = new VlcMedia(url, instance);
        player->open(media);
    }
}

void Widget::on_pushButton_pause_clicked(bool checked)
{
    if(checked)
        ui->pushButton_pause->setText("继续");
    else
        ui->pushButton_pause->setText("暂停");
    player->togglePause();
}

void Widget::on_pushButton_stop_clicked()
{
    player->stop();
}

