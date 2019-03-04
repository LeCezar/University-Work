#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_clicked()
{
    QString id,man,model,url,price,q;
    id=ui->lineEdit->displayText();
    man=ui->lineEdit_2->displayText();
    model=ui->lineEdit_3->displayText();
    url=ui->lineEdit_4->displayText();
    price=ui->lineEdit_5->displayText();
    q=ui->lineEdit_6->displayText();
    string i,m,mo,u,p,qn;
    i=id.toLocal8Bit().constData();
    m=man.toLocal8Bit().constData();
    mo=model.toLocal8Bit().constData();
    u=url.toLocal8Bit().constData();
    p=price.toLocal8Bit().constData();
    qn=q.toLocal8Bit().constData();
    int prc,quantity,idd,rez;
    idd=stoi(i);
    prc=stoi(p);
    quantity=stoi(qn);
//    Phone ph(idd,m,mo,u,prc,quantity);
    rez=c->addC(idd,m,mo,u,prc,quantity);
    this->close();
    this->destroy();

}
