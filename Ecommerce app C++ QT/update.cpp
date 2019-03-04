#include "update.h"
#include "ui_update.h"

update_phone::update_phone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::update_phone)
{
    ui->setupUi(this);
}

update_phone::~update_phone()
{
    delete ui;
}



void update_phone::on_pushButton_clicked()
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



        Phone ph;

        if(id!=""){
                    idd=stoi(i);
            ph.setId(idd);
        }
        if(man != ""){
            ph.setManufacturer(m);
        }
        if(model!=""){
            ph.setModel(mo);
        }
        if(url!=""){

            ph.setPhoto(u);
        }
        if(price!=""){
                    prc=stoi(p);
            ph.setPrice(prc);
        }
        if(q!=""){
                    quantity=stoi(qn);
            ph.setQuantity(quantity);
        }
        rez=c->update(ph);
        this->close();
        this->destroy();
}
