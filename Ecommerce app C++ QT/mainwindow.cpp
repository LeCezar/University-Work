#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminhud.h"
#include "customerhud.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

}

void MainWindow::on_LogInButton_clicked()
{
    if(ui->checkBox->isChecked()==true){
    Controller c{new repoHTML};
    this->c=c;
}
    string file="/Users/LeCezar/Desktop/Lab_11-12/phones_CSV";
    try{
         c.loadFromFileC(file);
    }
         catch(FileException& e){
             ui->Login_Ver_Label->setText("Error opening file!");
         }

    QString qstr;
    QString qstr2,qstr3;
    QString h="customer", usr="admin",pass="admin";
    qstr=ui->lineEdit->displayText();
    qstr2=ui->lineEdit_2->displayText();

    if(qstr==usr && pass==qstr2)
    {
        AdminHUD* ah=new AdminHUD;
        ah->setController(&this->c);

                    ah->show();
                    this->close();

}
            else{
        qstr3=ui->lineEdit->displayText();
            if(qstr3==h){
                CustomerHUD* ch = new CustomerHUD;
                ch->setController(&c);
                ch->show();
                this->close();


}
}
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    this->on_LogInButton_clicked();
}
