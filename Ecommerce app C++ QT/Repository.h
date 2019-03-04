//
// Created by Cezar Olteanu on 3/25/18.
//

#ifndef CODE_5_6_REPOSITORY_H
#define CODE_5_6_REPOSITORY_H

#include <vector>
#include "Phone.h"
#include "RepositoryException.h"

using namespace std;
class Repository {
protected:
    vector<Phone> phones;

public:
    Repository()= default;
    ~Repository();
    Phone getObject(int pos);
    void addPhone(Phone p);
    void deletePhone(int id);
    int findPoz(int id);
    Phone findObject(int id);
    void updateMandM(const string& man,const string& mod,int pos);
    void updateQuantity(int q, int pos);
    void updatePrice(int p,int pos);
    void updatePhoto(const string&  ph,int pos);
    vector<string> printRepo();
    void showPhoneAtPos(int pos);
    unsigned long length();
    void showRepo();
    void readFromFile(string& filename);
    virtual void writeToFile(string& filename);

};


class repoCSV : public Repository{
public:
    repoCSV(){

    };
    ~repoCSV(){

    };
    virtual void writeToFile(string& filneame);

};
class repoHTML : public repoCSV{
public:
    repoHTML(){

    };
    ~repoHTML(){

    };
    void writeToFile(string& filename);

};
void testRepo();


#endif //CODE_5_6_REPOSITORY_H
