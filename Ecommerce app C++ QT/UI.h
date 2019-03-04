//
// Created by Cezar Olteanu on 3/27/18.
//

#ifndef CODE_5_6_UI_H
#define CODE_5_6_UI_H

#include "Controller.h"
#include <iostream>
using namespace std;

class UI {
    Controller c;
public:
    UI()= default;
    void menuAdmin();
    int checkLogin();
    void updateMenu(int id);
    void start();
    void updateHandler(int id);
    void rezultat(int r);

};


#endif //CODE_5_6_UI_H
