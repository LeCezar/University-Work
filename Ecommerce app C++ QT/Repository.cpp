//
// Created by Cezar Olteanu on 3/25/18.
//

#include "Repository.h"
#include <cassert>
#include <fstream>
Repository::~Repository() {

}

void Repository::addPhone(Phone p) {
    phones.push_back(p);
}
void Repository::deletePhone(int pos) {
    phones.erase(phones.begin()+pos);
}
int Repository::findPoz(int id) {
    for (int i=0;i < phones.size();i++){
        if(phones[i].getId()==id)
        {
            return i;
        }
    }
    return -1;
}
Phone Repository::findObject(int id){
    return phones[id];

}
void Repository::showPhoneAtPos(int pos) {
    phones[pos].showPhone();

}
void Repository::showRepo() {
    if(phones.size()!=0) {
        for (int i = 0; i < phones.size(); i++) {
            if(phones[i].getQuantity()!=0)
            {
                phones[i].showPhone();
            }

        }
    }
}
void Repository::updateMandM(const string& man,const string& mod,int pos) {
    phones[pos].setManufacturer(man);
    phones[pos].setModel(mod);
}
void Repository::updateQuantity(int q, int pos)
{
    phones[pos].setQuantity(q);
}
void Repository::updatePrice(int p,int pos){
    phones[pos].setPrice(p);
}
void Repository::updatePhoto(const string&  ph,int pos){
    phones[pos].setPhoto(ph);
}
vector<string> Repository::printRepo() {
    vector<string> printR;
    if(phones.size()!=0) {
        for (int i = 0; i < phones.size(); i++) {
            printR.push_back(phones[i].printPhone());
        }
    }
    return printR;
}
Phone Repository::getObject(int pos){

    return phones[pos];
}
unsigned long Repository::length(){
    return phones.size();
}
void Repository::readFromFile(string& filename)
{
    ifstream file(filename);

    if (!file.is_open())
        throw FileException("The file could not be opened!");

    Phone s;
    while (file >> s)
        this->phones.push_back(s);

    file.close();
}
void Repository::writeToFile(string &filename) {
    ofstream file(filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");

    for (auto s : this->phones)
    {
        file << s;
    }

    file.close();
}

void repoCSV::writeToFile(string& filename)
{
    ofstream file(filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");

    for (auto s : this->phones)
    {
        file << s;
    }

    file.close();
}
void repoHTML::writeToFile(string &filename){
    repoCSV::writeToFile(filename);
    std::size_t found = filename.find("cart");
    if(found!=std::string::npos){
        filename="/Users/LeCezar/Desktop/Lab_11-12/cart_HTML";
    }
    else
         filename="/Users/LeCezar/Desktop/Lab_11-12/phones_HTML";

    ofstream file(filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");
    file << "<!DOCTYPE html> <html>";
    file << "<head>";
    file << "    <title>Phone list</title>";
    file <<"</head> <body>";
    file <<"<table border=\"1\">";
    file <<"    <tr>";
    file <<"    <td>Manufacturer</td> <td>Model</td> <td>Photo</td> <td>Price</td><td>Quantity</td>";
    file <<"    </tr>";
    for(int i=0; i < phones.size();i++){
        file <<"    <tr>";
        file <<"    <td>"<<phones[i].getManufacturer()<<"</td>"<<" <td>"<<phones[i].getModel()<<"</td>"<<" <td><a href=\""<<phones[i].getPhoto()<<"\">Photo</a></td>"<<" <td>"<<phones[i].getPrice()<<"$</td>"<<" <td>"<<phones[i].getQuantity()<<"</td>\n";
        file <<"    </tr>";
    }

    file <<"</table>";
    file <<"</body> </html>";
}
void  testRepo() {
    Repository repo;
    Phone galaxy(100, "Samsung", "Galaxy S9", "https://i.gadgets360cdn.com/products/large/1519585124_635_samsung_galaxy_s9_blue.jpg", 830, 2);
    Phone apple(200, "Samsung 2", "Galaxy S8", "https://i.gadgets360cdn.com/products/large/1519585124_635_samsung_galaxy_s9_blue.jpg", 830, 2);
    Phone motorola(100, "Samsung 3", "Galaxy S7", "https://i.gadgets360cdn.com/products/large/1519585124_635_samsung_galaxy_s9_blue.jpg", 830, 2);
    repo.addPhone(galaxy);
    repo.addPhone(apple);
    repo.addPhone(motorola);
    repo.updatePhoto("https://www.apple.com/",1);
    assert(repo.getObject(1).getPhoto() == "open https://www.apple.com/");
    repo.updatePrice(500, 1);
    assert(repo.getObject(1).getPrice() == 500);
    repo.updateQuantity(10, 1);
    assert(repo.getObject(1).getQuantity() == 10);


    assert(repo.length() == 3);
    repo.updateMandM("Apple", "Iphone X", 0);
    assert(repo.getObject(0).getManufacturer() == "Apple");
    assert(repo.getObject(0).getModel() == "Iphone X");
    repo.deletePhone(0);
    assert(repo.length() == 2);
}
