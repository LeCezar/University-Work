#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Controller.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Controller c;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_LogInButton_clicked();

    void on_lineEdit_2_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
