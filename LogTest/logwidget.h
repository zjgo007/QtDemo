#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QMutex>
#include <QTextStream>

namespace Ui {
class LogWidget;
}

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = nullptr);
    ~LogWidget();

private:
    Ui::LogWidget *ui;
    static LogWidget* _pt;
    static bool outputToFile;
    static void myLogOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    const  QtMessageHandler messageHandler = qInstallMessageHandler(nullptr);

signals:
    void logOutputed(QString log);
private slots:
    void on_radioButton_ToFile_clicked();
    void on_radioButton_toControl_clicked();
    void showLog(QString log);
    void on_radioButton_ToDebug_clicked();
};

#endif // WIDGET_H
