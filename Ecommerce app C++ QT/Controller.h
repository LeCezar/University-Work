//
// Created by Cezar Olteanu on 3/25/18.
//

#ifndef CODE_5_6_CONTROLLER_H
#define CODE_5_6_CONTROLLER_H

#include "Repository.h"
#include "PhoneValidator.h"
#include <cassert>
class Controller {
    Repository* repo=new repoCSV;
    Repository* cart=new repoCSV;
    PhoneValidator validator;
    int Sum=0, iterator=-1;
public:
    Controller()= default;
    explicit Controller(Repository* _repo){
        this->repo=_repo;
        this->cart=_repo;
        Sum=0;
        iterator = -1; };
    int addC(int id,const string& man,const string& mod,const string& ph, int p, int q);
    int removeC(int id);
    int update(Phone p);
    void showCart();
    int next();
    int addToCart();
    vector<string> filterByPrice(int value);
    void saveToFileC(string& filename);
    void loadFromFileC(string& filename);
    void saveToFileC_CART(string& filename);
    Phone getPhoneAtPos(int pos,int which);

    int cart_length();



    vector<string>  printPhones();




};
void testController();


#endif //CODE_5_6_CONTROLLER_H
