#ifndef CMDTHREAD_H
#define CMDTHREAD_H

#include <QThread>
class CmdThread : public QThread
{
    Q_OBJECT
public:
    CmdThread();
    void config(QString cmd,
                QStringList params);

Q_SIGNALS:
    void dataSend(QString str);

protected:
    void run();



private:
    QString cmd;
    QStringList params;
};

#endif // CMDTHREAD_H
