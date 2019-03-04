#ifndef UPDATE_H
#define UPDATE_H

#include <QMainWindow>
#include "Controller.h"

namespace Ui {
class update_phone;
}

class update_phone : public QMainWindow
{
    Q_OBJECT
private:
    Controller* c;

public:
    explicit update_phone(QWidget *parent = 0);
    ~update_phone();
    void setController(Controller* _c){
        this->c=_c;
    }


private slots:
    void on_pushButton_clicked();

private:
    Ui::update_phone *ui;
};

#endif // UPDATE_H
