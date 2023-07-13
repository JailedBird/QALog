#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set splitter the adaptive size
    setCentralWidget(ui->splitter);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,4);
    workThread = new CmdThread();
    connect(workThread, SIGNAL(dataSend(QString)), this, SLOT(onShowChange(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    workThread->config("ping", QStringList()<<"-n"<<"16"<<"baidu.com");
    workThread->start();
}

void MainWindow::onShowChange(QString str)
{
    ui->plainTextEdit->appendPlainText(str);

}


void MainWindow::on_pushButton_4_clicked()
{
    if(workThread!=nullptr && workThread->isRunning()){
        workThread->terminate();
        workThread->wait();
    }
}

