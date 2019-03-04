//
// Created by Cezar Olteanu on 3/25/18.
//

#include "Phone.h"
#include <iostream>
#include <fstream>
using namespace std;
Phone::Phone(int id,const string& man,const string& mod,const string& ph, int p, int q) {
    Id=id;
    this->manufacturer=man;
    model=mod;
    photo="open ";
    photo+=ph;
    price=p;
    quantity=q;

}
Phone::Phone(const Phone &ph) {
    Id=ph.Id;
    manufacturer=ph.manufacturer;
    model=ph.model;
    photo=ph.photo;
    price=ph.price;
    quantity=ph.quantity;
}
Phone::Phone(){
    manufacturer="man";
    model="model";
    photo="open <URL>";
    price=-1;
    quantity=-1;
}
vector<string> Phone::showPhone() {
    string fek;
    vector<string> show;
    show.push_back("Manufacturer: "+ manufacturer);
    show.push_back("Model: "+model);
    show.push_back(photo);
    fek=to_string(price);
    show.push_back("Price: "+fek);
    fek=to_string(quantity);
    show.push_back("Quantity: "+fek);
    return show;


}
string Phone::printPhone(){
    string print="";
    print+=to_string(Id)+", ";
    print+=manufacturer+", ";
    print+=model+", ";
    print+=photo+", ";
    print+=to_string(price)+"€, ";
    print+=to_string(quantity);
    return print;
}
bool Phone::operator==(const Phone& p1) {
    if((p1.photo==this->photo) && (p1.manufacturer==this->manufacturer) && (p1.model==this->model) && (p1.quantity==this->quantity) && (p1.price==this->price) && (p1.Id==this->Id)){
        return true;
    }
    return false;
}
bool Phone::operator>(int value) {
    if(this->price > value){
        return true;
    }
    return false;
}
istream & operator>>(istream& is,Phone& ph){
    string line;
    getline(is, line);

    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 6) // make sure all the phone data was valid
        return is;

    ph.Id = stoi(tokens[0]);
    ph.manufacturer = tokens[1];
    ph.model = tokens[2];
    ph.photo = tokens[3];
    ph.price = stoi(tokens[4]);
    ph.quantity = stoi(tokens[5]);

    return is;
}
ostream& operator<<(ostream& os,Phone& ph){
    os << ph.Id<<","<<ph.manufacturer<<","<<ph.model<<","<<ph.photo<<","<<ph.price<<","<<ph.quantity<<"\n";
    return os;
}

