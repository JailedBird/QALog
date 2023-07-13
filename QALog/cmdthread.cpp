#include "cmdthread.h"
#include <QtDebug>
CmdThread::CmdThread()
{

}
void CmdThread::run()
{
    while(true)
    {
        sleep(1);
        for(int n=0;n<10;n++)
            qDebug()<<n<<n<<n<<n<<n<<n<<n<<n<<Qt::endl;

    }
}
