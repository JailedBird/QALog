#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cmdthread.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onShowChange(QString str);
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    CmdThread *workThread;

};

#endif // MAINWINDOW_H
