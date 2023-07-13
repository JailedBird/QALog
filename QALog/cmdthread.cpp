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

    if(myProcess.waitForStarted()){
        emit dataSend("启动成功");
    }
    else{
        emit dataSend(QString("启动失败 error:" + myProcess.errorString()));
        return;
    }

    // Loop for query
    while(!myProcess.waitForFinished(100))
    {
        auto bytes = myProcess.readAll();
        if(bytes.isEmpty()){
            continue;
        }
        auto res = QString::fromLocal8Bit(bytes);
        emit dataSend(res);
    }
    // Read last
    auto bytes = myProcess.readAll();
    if(!bytes.isEmpty()){
        emit dataSend(QString::fromLocal8Bit(bytes));
    }

}
