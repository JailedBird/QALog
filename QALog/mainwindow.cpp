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
    // set tool bar
    ui->setupUi(this);
    // 确保Spliter可以有效缩放
    setCentralWidget(ui->splitter);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,5);


//    auto splitter = new QSplitter(Qt::Horizontal);

//    auto leftLayout = new QVBoxLayout(new QWidget(splitter));
//    auto button1 = new QPushButton(tr("Start001"));
//    auto button2 = new QPushButton(tr("Start002"));
//    auto button3 = new QPushButton(tr("Start003"));
//    leftLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
//    leftLayout->addWidget(button1);
//    leftLayout->addWidget(button2);
//    leftLayout->addWidget(button3);

//    auto rightLayout = new QVBoxLayout(new QWidget(splitter));
//    auto right001 = new QLabel(tr("Output"));
//    auto rightEdit = new QTextEdit () ;


//    leftLayout->addWidget(button1);
//    leftLayout->addWidget(button2);
//    leftLayout->addWidget(button3);

//    rightLayout->addWidget(right001);
//    rightLayout->addWidget(rightEdit);
//    splitter->setStretchFactor(0,1);
//    splitter->setStretchFactor(1,3);
//    if(centralWidget()!=nullptr){
//        delete centralWidget();
//    }
//    setCentralWidget(splitter);


}

MainWindow::~MainWindow()
{
    delete ui;
}
