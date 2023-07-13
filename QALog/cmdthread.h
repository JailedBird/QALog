#ifndef CMDTHREAD_H
#define CMDTHREAD_H

#include <QThread>
class CmdThread : public QThread
{
    Q_OBJECT
public:
    CmdThread();
protected:
    void run();
};

#endif // CMDTHREAD_H
