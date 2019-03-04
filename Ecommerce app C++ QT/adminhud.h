#ifndef ADMINHUD_H
#define ADMINHUD_H

#include <QMainWindow>
#include "Controller.h"

namespace Ui {
class AdminHUD;
}

class AdminHUD : public QMainWindow
{
    Q_OBJECT
private:
    Controller* c;

public:
    explicit AdminHUD(QWidget *parent = 0);
    ~AdminHUD();
    void setController(Controller* _c){
        this->c=_c;
    }
    void print_to_widget(vector<string> list);

private slots:

    void on_print_button_clicked();

    void on_AdminHUD_destroyed();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_add_button_clicked();

    void on_update_button_clicked();

private:
    Ui::AdminHUD *ui;
};

#endif // ADMINHUD_H
