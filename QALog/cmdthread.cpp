#include "cmdthread.h"
#include <QtDebug>
#include <QDateTime>
#include <QProcess>
CmdThread::CmdThread()
{

}

void CmdThread::config(QString cmd, QStringList params)
{
    this->cmd = cmd;
    this->params = params;

}

void CmdThread::run()
{
    // 错误处理相关的方案：https://blog.51cto.com/u_9695930/5068852
    // 返回读取：https://blog.csdn.net/weixin_43246170/article/details/115866322
    QProcess myProcess;
    myProcess.start(this->cmd, this->params);
    //    myProcess.closeReadChannel(QProcess::StandardOutput);
    //    myProcess.closeReadChannel(QProcess::StandardError);
    //    myProcess.closeWriteChannel();

    if(myProcess.waitForStarted())
    {
        qDebug()<<"启动成功";
    }
    else
    {
        qDebug()<<"启动失败 error:"<<myProcess.errorString();
                                         return;
    }
    int count =0;
    // Loop for query
    while(!myProcess.waitForFinished(100))
    {
        auto ret = myProcess.readAll();
        if(ret.isEmpty()){
            continue;
        }
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
        auto res = current_date + ":\t" +QString::fromLocal8Bit(ret);
        qDebug()<<res;
        emit dataSend(res);

    }
    // Read last
    auto ret = myProcess.readAll();
    if(!ret.isEmpty()){
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
        auto res = current_date + ":\t" +QString::fromLocal8Bit(ret);
        qDebug()<<res;
        emit dataSend(res);
    }

}
