#include "draftwindow.h"
#include "ui_draftwindow.h"

DraftWindow::DraftWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DraftWindow)
{
    ui->setupUi(this);
}

DraftWindow::~DraftWindow()
{
    delete ui;
}
