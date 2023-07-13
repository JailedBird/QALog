#ifndef DRAFTWINDOW_H
#define DRAFTWINDOW_H

#include <QMainWindow>

namespace Ui {
class DraftWindow;
}

class DraftWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DraftWindow(QWidget *parent = nullptr);
    ~DraftWindow();

private:
    Ui::DraftWindow *ui;
};

#endif // DRAFTWINDOW_H
