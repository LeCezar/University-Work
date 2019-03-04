//
// Created by Cezar Olteanu on 3/25/18.
//

#include "Controller.h"
#include <iostream>


int Controller::addC(int id, const string &man, const string &mod, const string &ph, int p, int q) {
    if(repo->findPoz(id)!=-1)
    {
        return 0;
    }

    Phone phone(id,man,mod,ph,p,q);
    this->validator.validate(phone);
    repo->addPhone(phone);
    return 1;
}
void Controller::saveToFileC_CART(string &filename) {
    this->cart->writeToFile(filename);
}
void Controller::saveToFileC(string& filename){
    this->repo->writeToFile(filename);

};
Phone Controller::getPhoneAtPos(int pos,int which){
    Phone ph;
    if(which == 1 )
    ph=repo->findObject(pos);
    if(which == 2)
    ph=cart->findObject(pos);
    return ph;
}

void Controller::loadFromFileC(string &filename) {

    this->repo->readFromFile(filename);
}
int Controller::removeC(int id) {
    int pos=-1;
    pos=repo->findPoz(id);
    if(pos==-1)
    {
        return 0;
    }
    repo->deletePhone(pos);
    return 1;

}
int Controller::update(Phone after) {
    // Updates the phone at the given id to the new changes (changes are considered anything that is different from the basic
    // constructor of the class Phone)
    if(repo->findPoz(after.getId())==-1)
    {
        return 0;
    }
    Phone before;
    int pos;
    pos=repo->findPoz(after.getId());
    if(pos!=-1) {
        if (after.getModel() != "model") {
            repo->updateMandM(after.getManufacturer(), after.getModel(), pos);
        }
        if (after.getPhoto() != "open <URL>") {
            repo->updatePhoto(after.getPhoto(), pos);
        }
        if (after.getQuantity() != -1) {
            repo->updateQuantity(after.getQuantity(), pos);
        }
        if (after.getPrice() != -1) {
            repo->updatePrice(after.getPrice(), pos);
        }
        return 1;
    }
    return 0;
}
vector<string>  Controller::printPhones() {
    return repo->printRepo();
}
int Controller::cart_length(){
    return cart->length();
}
int Controller::next(){
    // iterates trough the phones and siplays the current one
    this->iterator++;
    if(iterator == repo->length())
    {
        this->iterator=0;
    }
    return this->iterator;

}
int Controller::addToCart(){
    // makes a copy of the object in repository then adds it to cart
    // if the obj already exists, it just adds +1 to the quantity
    int pos=this->iterator;
    Phone purchased,aux;
    purchased=repo->getObject(pos);
    int quantity,qaux,posaux;
    quantity=purchased.getQuantity();
    repo->updateQuantity(quantity-1,pos);
    if(cart->findPoz(purchased.getId()) == -1){
        purchased.setQuantity(1);
        cart->addPhone(purchased);
    }
    else{
        aux=cart->findObject(purchased.getId());
        posaux=cart->findPoz(purchased.getId());
        qaux=aux.getQuantity();
        cart->updateQuantity(qaux+1,posaux);

    }

    this->Sum+=purchased.getPrice();
    return Sum;
}
void Controller::showCart() {
    cart->showRepo();
    cout<<"Total price: "<<this->Sum;
}

vector<string>  Controller::filterByPrice(int value){
    vector<string> filtered;
    for(int i=0;i<repo->length();i++){
        if(repo->getObject(i).getPrice() > value){
            filtered.push_back(repo->getObject(i).printPhone());

        }
    }
    return filtered;
}
void testController() {
    Controller c;
    Phone p;
    p.setId(100);
    p.setPrice(100);
    p.setManufacturer("Apple");
    p.setModel("Ipad Pro");
    p.setPhoto("https://www.apple.com/");
    p.setQuantity(100);
    assert(c.addC(100, "Samsung", "Galaxy S9", "https://i.gadgets360cdn.com/products/large/1519585124_635_samsung_galaxy_s9_blue.jpg", 830, 2) == 1);
    assert(c.update(p) == 1);
    assert(c.removeC(100) == 1);
}

