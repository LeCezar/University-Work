#include "customerhud.h"
#include "ui_customerhud.h"
#include <stdlib.h>
#include <mainwindow.h>

CustomerHUD::CustomerHUD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerHUD)
{
    ui->setupUi(this);
}
void CustomerHUD::setController(Controller * c){
    this->c=c;
}

CustomerHUD::~CustomerHUD()
{
    delete ui;
}

void CustomerHUD::on_pushButton_clicked()
{
    int iter;
    iter=c->next();
    Phone ph;
    vector<string> show;
    ph=c->getPhoneAtPos(iter,1);
    show=ph.showPhone();
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(show[0]));
    ui->listWidget->addItem(QString::fromStdString(show[1]));
    ui->listWidget->addItem(QString::fromStdString(show[3]));
    ui->listWidget->addItem(QString::fromStdString(show[4]));
    string photo= "open ";
//    photo+=show[2];



}

void CustomerHUD::on_pushButton_4_clicked()
{
    string file="/Users/LeCezar/Desktop/Lab_11-12/cart_CSV";
    c->saveToFileC_CART(file);

    file="/Users/LeCezar/Desktop/Lab_11-12/phones_CSV";
    c->saveToFileC(file);
    MainWindow* w = new MainWindow;
    w->show();
    this->close();
    this->destroy();
}

void CustomerHUD::on_pushButton_2_clicked()
{
    this->sum=c->addToCart();
    QString qstr;
    qstr="Cart price: ";
    qstr+=QString::number(sum);
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(qstr);


}

void CustomerHUD::on_pushButton_3_clicked()
{
    QString qstr;
    qstr="Cart price: ";
    qstr+=QString::number(this->sum);
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(qstr);
    for(int i=0;i<c->cart_length();i++){
        Phone ph;
        ph=c->getPhoneAtPos(i,2);
        vector<string> show=ph.showPhone();
        ui->listWidget_2->addItem("-------------------------------------------------");
        ui->listWidget_2->addItem(QString::fromStdString(show[0]));
        ui->listWidget_2->addItem(QString::fromStdString(show[1]));
        ui->listWidget_2->addItem(QString::fromStdString(show[3]));
        ui->listWidget_2->addItem(QString::fromStdString(show[4]));
        ui->listWidget_2->addItem("-------------------------------------------------");

    }
}
