#include "adminhud.h"
#include "ui_adminhud.h"
#include <string>;
#include <vector>;
#include <mainwindow.h>
#include "add.h"
#include "update.h"

AdminHUD::AdminHUD(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::AdminHUD)
{
    ui->setupUi(this);
}


AdminHUD::~AdminHUD()
{
    delete ui;
}
void AdminHUD::print_to_widget(vector<string> list){

    ui->listWidget->clear();
    for(int i=0;i<list.size();i++){
        ui->listWidget->addItem(QString::fromStdString(list[i]));
    }
}

void AdminHUD::on_print_button_clicked()
{
    vector<string> list;
    list=c->printPhones();
    this->print_to_widget(list);

}

void AdminHUD::on_AdminHUD_destroyed()
{

}

void AdminHUD::on_pushButton_clicked()
{
    string file="/Users/LeCezar/Desktop/Lab_11-12/phones_CSV";
    c->saveToFileC(file);
    MainWindow* w = new MainWindow;
    w->show();
    this->close();
    this->destroy();

}

void AdminHUD::on_lineEdit_returnPressed()
{
    QString qstr;
    qstr=ui->lineEdit->displayText();
    string nr;
    nr=qstr.toLocal8Bit().constData();
    int price;
    price=stoi(nr);
    this->print_to_widget(c->filterByPrice(price));
}

void AdminHUD::on_lineEdit_2_returnPressed()
{
    QString qstr;
    qstr=ui->lineEdit_2->displayText();
    string nr;
    nr=qstr.toLocal8Bit().constData();
    int id, rezultat;
    id=stoi(nr);
    rezultat = c->removeC(id);
    this->on_print_button_clicked();
}

void AdminHUD::on_add_button_clicked()
{
    add* ad = new add;
    ad->setController(this->c);
    ad->show();

}

void AdminHUD::on_update_button_clicked()
{
    update_phone* up = new update_phone;
    up->setController(this->c);
    up->show();
}
