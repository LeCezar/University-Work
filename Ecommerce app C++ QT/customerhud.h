#ifndef CUSTOMERHUD_H
#define CUSTOMERHUD_H

#include <QMainWindow>
#include <Controller.h>

namespace Ui {
class CustomerHUD;
}

class CustomerHUD : public QMainWindow
{
    Q_OBJECT
private:
    Controller* c;
    int sum;

public:
    explicit CustomerHUD(QWidget *parent = 0);
    ~CustomerHUD();
    void setController(Controller* c);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CustomerHUD *ui;
};

#endif // CUSTOMERHUD_H
