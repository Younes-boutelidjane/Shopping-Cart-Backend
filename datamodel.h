#include <string>
#include <unordered_map>

using namespace std;

class Item;
class Cart;

class Product
{
private:
    int Price;
    string Name;
    int ID;
public:
    Product(){}
    Product(int u_id, string Name, int Price){
        ID = u_id;
        this->Name = Name;
        this->Price = Price;
    }

    string getDisplayName(){
        return Name + " : $" + to_string(Price) + "\n";
    }

    string getShortName(){
        return Name.substr(0,1);
    }

    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int quantity;

public:
    Item(){}
    Item(Product p, int q): product(p), quantity(q){}

    int getItemPrice(){
        return quantity * product.Price;
    }

    string getItemInfo(){
        return to_string(quantity)+ " x " + product.Name + ": $ "+ to_string(quantity * product.Price)+'\n';
    }

    friend class Cart;
};

class Cart{
    std::unordered_map<int, Item> items;
public:
    void addProduct(Product product){
        if(items.count(product.ID) == 0){
            Item newItem(product, 1);
            items[product.ID] = newItem;
        }
        else{
            items[product.ID].quantity +=1;
        }
    }

    int getTotal(){
        int total = 0;
        for(const auto &itemPair : items){
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }

    string viewCart(){
        if(items.empty()){
            return "Cart is empty";
        }

        string itemizedList;
        int cart_total = getTotal();

        for(const auto &itemPair : items){
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }

        return itemizedList + "\n Total Amount : $" + to_string(cart_total) + '\n';
    }

    bool isEmpty(){
        return items.empty();
    }
};


