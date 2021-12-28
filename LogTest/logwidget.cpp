#include "logwidget.h"
#include "ui_logwidget.h"

LogWidget* LogWidget::_pt = nullptr;
bool LogWidget::outputToFile = false;

LogWidget::LogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWidget)
{
    ui->setupUi(this);
    _pt = this;
    connect(this,SIGNAL(logOutputed(QString)),this,SLOT(showLog(QString)));
    qInstallMessageHandler(LogWidget::myLogOutput);
}

LogWidget::~LogWidget()
{
    delete ui;
}

void LogWidget::myLogOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{

    static QMutex mutex;
    mutex.lock();
    QString textTypeStr;
    switch (type) {
    case QtDebugMsg:
        textTypeStr = "<<Debug>>";
        break;
    case QtInfoMsg:
        textTypeStr = "<<Info>>";
        break;
    case QtWarningMsg:
        textTypeStr = "<<Warning>>";
        break;
    case QtCriticalMsg:
        textTypeStr = "<<Critical>>";
        break;
    case QtFatalMsg:
        textTypeStr = "<<Fatal>>";
        break;
    }
//    QString context_info = QString("FILE:(%1) Line:(%2)").arg(QString(context.file),QString(context.line));
    QString current_data_time = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss]");
    QString message = current_data_time+" "+textTypeStr+" "+" "+msg;
    if(outputToFile){
        QString LogName = "Log.txt";
        QFile file(LogName);
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream<<message<<"\r\n";
        file.close();
    }else{
      emit _pt->logOutputed(message);
    }

    mutex.unlock();
}


void LogWidget::on_radioButton_ToFile_clicked()
{
    outputToFile = true;
    qInstallMessageHandler(LogWidget::myLogOutput);
}

void LogWidget::on_radioButton_toControl_clicked()
{
    outputToFile = false;
    qInstallMessageHandler(LogWidget::myLogOutput);
}

void LogWidget::showLog(QString log)
{
    ui->plainTextEdit->appendPlainText(log);
}

void LogWidget::on_radioButton_ToDebug_clicked()
{
    qInstallMessageHandler(messageHandler);
}
