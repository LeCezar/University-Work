//
// Created by Cezar Olteanu on 3/25/18.
//

#pragma once


#include <string>
#include "Utilities.h"

using namespace std;
class Phone {
    string manufacturer;
    string model;
    string photo;
    int price;
    int quantity;
    int Id;

public:
    Phone(int id,const string& man,const string& mod,const string& ph, int p, int q);
    Phone();
    Phone(const Phone&);

    string getManufacturer(){return manufacturer;};
    string getModel(){return model;};
    string getPhoto(){return photo;};
    int getPrice(){return price;};
    int getQuantity(){return quantity;};
    int getId(){return Id;};
    void setManufacturer(const string& man){manufacturer=man;};
    void setModel(const string& mod){model=mod;};
    void setPhoto(const string& ph){
        photo="open ";
        photo+=ph;
    };
    void setId(int id){Id=id;};
    void setPrice(int p){price=p;};
    void setQuantity(int q){quantity=q;};
    vector<string> showPhone();
    string printPhone();

private:
    bool operator==(const Phone& p1);
    bool operator>(int value);
    friend istream & operator>>(istream& is,Phone& ph);
    friend ostream& operator<<(ostream& os,Phone& ph);
};


