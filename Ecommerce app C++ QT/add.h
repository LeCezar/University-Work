#ifndef ADD_H
#define ADD_H

#include <QMainWindow>
#include "Controller.h"

namespace Ui {
class add;
}

class add : public QMainWindow
{
    Q_OBJECT
private:
    Controller* c;

public:
    explicit add(QWidget *parent = 0);
    ~add();
    void setController(Controller* _c){
        this->c=_c;
    }


private slots:
    void on_pushButton_clicked();

private:
    Ui::add *ui;
};

#endif // ADD_H
