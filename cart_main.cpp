#include <iostream>
#include <vector>
#include "datamodel.h"

vector<Product> allProducts={
    Product(1, "apple", 5),
    Product(2, "banana", 3),
    Product(3, "orange", 4),
    Product(4, "mango", 7)
};

Product* ChooseProduct(){
    string product_list;
    cout << "Available Products " << endl;

    for(auto product : allProducts){
        product_list.append(product.getDisplayName());
    }
    cout << product_list << endl;

    cout << "--------------------------"<< endl;
    string choice;
    cin>>choice;
    for (int i = 0; i < allProducts.size(); ++i) {
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i];
        }
    }
    cout << "Product was not fount"<< endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout << "Pay in Cash: ";

    int paid;
    cin >> paid;

    if(paid >= total){
        cout << "Change " << paid - total << endl;
        cout << "Thank you for shopping"<<endl;
        return true;
    }
    else{
        cout << "Not enought Cash"<<endl;
        return false;
    }
}


int main(){
    char action;
    Cart cart;

    while(true){
        cout << "select an action - (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin >> action;

            if(action == 'a' )
            {
                //TODO : add an item
                // View All Products + choose product +  add to the cart
                Product *product = ChooseProduct();
                if(product != NULL){
                    cout << "added to the cart " << product->getDisplayName()<<endl;
                    cart.addProduct(*product);
                }}

            if(action == 'v'){
                cout << "---------------------\n";
                cout << cart.viewCart()<<endl;
                cout << "---------------------\n";
            }


            if(action == 'c') {
                cout << cart.viewCart()<<endl;
                if(checkout(cart)){
                    exit(0);
                }

            }


        }
}

