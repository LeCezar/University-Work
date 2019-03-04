//
// Created by Cezar Olteanu on 3/27/18.
//

#include "UI.h"
int UI::checkLogin() {
    string user,password;
    while(1)
    { cout<<"User: ";
    getline(cin,user);
    cout<<"Password: ";
    getline(cin,password);
    if((user=="admin") && (password == "admin"))
        return 1;
    else
        if(user=="customer")
            return 2;
        else
            cout<<"Try again!! (For customer user=customer, For admin user= admin, password=admin";

    }


}
void UI::rezultat(int r){
    if(r==0)
        cout<<"Phone already exists!\n";
    if(r==1)
        cout<<"Success! \n";
}
void UI::updateMenu(int id) {
    cout<<"---------------------------------------\n";
    cout<<"Updating for ID: "<<id<<"\n";
    cout<<"1. Update M&M: \n";
    cout<<"2. Update photo: \n";
    cout<<"3. Update price: \n";
    cout<<"4. Update quantity \n";
    cout<<"0. Back \n";
    cout<<"---------------------------------------";
}
void UI::updateHandler(int id){
    int choice;
    Phone p;
    p.setId(id);
    while(1) {
        updateMenu(id);
        cout << "Input choice >> ";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
            break;
        switch (choice) {
            case 1: {
                string man, model;
                int r;
                cout << "Update Manufacturer: ";
                getline(cin, man);
                cout << "Update Model: ";
                getline(cin, model);
                p.setManufacturer(man);
                p.setModel(model);
                r=c.update(p);
                rezultat(r);
                break;


            }
            case 2: {
                string photo;
                int r;
                cout << "Updated URL: ";
                getline(cin, photo);
                p.setPhoto(photo);
                r = c.update(p);
                rezultat(r);
                break;
            }
            case 3:{
                int price;
                int r;
                cout << "Updated price: ";
                cin>>price;
                cin.ignore();
                p.setPrice(price);
                r = c.update(p);
                rezultat(r);
                break;
            }
            case 4:
            {
                int quantity;
                int r;
                cout << "Updated quantity: ";
                cin>>quantity;
                cin.ignore();
                p.setQuantity(quantity);
                r = c.update(p);
                rezultat(r);
                break;
            }

        }
    }


}
void UI::menuAdmin() {
    cout<<"---------------------------------------\n";
    cout<<"1.Add a phone\n";
    cout<<"2.Delete a phone\n";
    cout<<"3.Update a phone\n";
    cout<<"4.Print all phones\n";
    cout<<"5.Filter by price > \n";
    cout<<"0. Exit\n";
    cout<<"---------------------------------------";
}

void UI::start() {
    int user;
    user=checkLogin();
    string filename,html;
    cout<<"Would you like to generate an html file when saving/exiting? (yes/no)";
    getline(cin,html);
    if(html=="yes" or html == "YES" or html=="Yes"){
        Controller c{new repoHTML};
        this->c = c;
    }
    int opened =0;
    while(opened==0) {
        cout << "What file should we load from: ";
        getline(cin, filename);
        opened=1;
        try {
            c.loadFromFileC(filename);
        }
        catch (FileException &e) {
            cout << e.what() << endl;
            opened=0;
        }
    }




//    c.addC(1,"Samsung","Galaxy S9","https://i.gadgets360cdn.com/products/large/1519585124_635_samsung_galaxy_s9_blue.jpg",830,5);
//    c.addC(2,"Samsung","Galaxy S8","https://pisces.bbystatic.com/image2/BestBuy_US/images/products/5770/5770900cv20d.jpg",700,2);
//    c.addC(3,"Samsung","Galaxy S7 Edge","https://images.kogan.com/image/fetch/s--7-QFdyHL--/b_white,c_pad,f_auto,h_400,q_auto:good,w_600/https://assets.kogan.com/files/product/KHSGS732/KHSGS7E32BLK_1v2.jpg",500,1);
//    c.addC(4,"Apple","Iphone X","https://cdn.macrumors.com/article-new/2017/10/iphone-x-silver.jpg",1000,10);
//    c.addC(5,"Apple","Iphone 8+","https://store.storeimages.cdn-apple.com/4974/as-images.apple.com/is/image/AppleInc/aos/published/images/i/ph/iphone8/plus/iphone8-plus-spgray-select-2017?wid=513&hei=556&fmt=jpeg&qlt=95&op_usm=0.5,0.5&.v=1504041012436",850,8);
//    c.addC(6,"LG","V30","https://ss7.vzw.com/is/image/VerizonWireless/lg-v30-kf-1-d-0917?$pngalpha$&scl=1",700,6);
//    c.addC(7,"OnePlus","5T","https://cnet2.cbsistatic.com/img/T_Lgv0_yIfpEJg5RPUwSOY1BLpU=/770x433/2017/11/28/326ee081-c1fb-4f52-9964-6e92d9d14255/oneplus-5t-header.jpg",500,10);
//    c.addC(8,"OnePlus","3T","https://cnet2.cbsistatic.com/img/UHZvp-ldibQV3yePpXRhP-kGEQQ=/770x433/2017/01/24/a5a951ec-acfa-4ecb-9e2c-2ebaf61d0283/oneplus-3t-header.jpg",400,2);
//    c.addC(9,"Google","Pixel 2 XL","https://drop.ndtv.com/TECH/product_database/images/104201774205PM_635_google_pixel_2_xl.jpeg",850,12);
    if(user==1){
        while(1){
            int command;
            menuAdmin();
            cout<<"Input choice >> ";
            cin>>command;
            cin.ignore();
            if(command==0){
                c.saveToFileC(filename);
                cout<<"Logout...";
                break;
            }
            else{
                switch(command) {
                    case 1: {
                        string man, model, photo;
                        int price, quantity, id,rez;
                        cout << "Id: ";
                        cin >> id;
                        cin.ignore();
                        cout << "Manufacturer: ";
                        getline(cin, man);
                        cout << "Model: ";
                        getline(cin, model);
                        cout << "URL: ";
                        getline(cin, photo);
                        cout << "Price: ";
                        cin >> price;
                        cin.ignore();
                        cout << "Quantity: ";
                        cin >> quantity;
                        cin.ignore();
                        try {
                            rez = c.addC(id, man, model, photo, price, quantity);
                        }
                        catch(PhoneException& e){
                            for (auto s : e.getErrors())
                                cout << s;
                            rez=0;
                        }
                        catch (RepositoryException& e)
                        {
                            cout << e.what() << endl;
                            rez=0;
                        }
                        catch (FileException& e)
                        {
                            cout << e.what() << endl;
                            rez=0;
                        }
                        rezultat(rez);
                        break;
                    }
                    case 2: {
                        int id,rez;
                        cout<<"Id of the phone you wish to remove: ";
                        cin>>id;
                        cin.ignore();
                        rez=c.removeC(id)==0;
                        rezultat(rez);
                        break;
                    }
                    case 3:
                    {
                        int id;
                        cout<<"Id of object to update >> ";
                        cin>>id;
                        cin.ignore();
                        updateHandler(id);
                        break;
                    }
                    case 4:
                    {
                        c.printPhones();
                        break;
                    }
                    case 5:
                    {
                        int price;
                        cout<<"Price for filtering >>  ";
                        cin>>price;
                        cin.ignore();
                        c.filterByPrice(price);

                    }
                }
            }
        }

    }
    if(user == 2){
        string input;
        int pos,sum;
        cout<<"Input options: y - buy\n";
        cout<<"               n - next/skip \n";
        cout<<"               c - prints the current shopping list \n";
        cout<<"               s - stop/exit \n";
        pos = c.next();
        while(true) {

            getline(cin,input);
            if (input == "n") {
                pos = c.next();
            }
            else {
                if (input == "y") {
                    cout << "Phone added \n";
                    cout << "Total price = " << c.addToCart();

                }
                else {
                    if (input == "s") {
                        if(html=="yes" or html == "YES" or html=="Yes"){
                            string file="phones";
                            c.saveToFileC_CART(file);
                        }
                        cout << "Bye!";
                        break;
                    }
                    else {
                        if (input == "c") {
                            c.showCart();


                        }
                        else cout<<"Wrong command";
                    }
                }
            }


        }

    }

}
