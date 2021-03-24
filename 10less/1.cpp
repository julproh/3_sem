//Умные указатели

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Item{
    public: 
    Item() : n(0), d(0.0) {cout << "Item create" << endl;}
    Item (int n, double d) {cout << "qwe"<< endl;}
    ~Item() {cout << "Item destroy" << endl;}
    weak_ptr<Item> p; // указатель наблюдатель
    private:
    int n;
    double d;

};

int main() {
    //умный указатель 1
    unique_ptr<Item> item1 (new Item);
    unique_ptr<Item> item2 (new Item);
    unique_ptr<Item> item3 = move(item1);

    cout << "item: " << static_cast<bool>(item1) << endl;

    unique_ptr <Item>  item4 =  make_unique<Item> (23, 23.5);

    //Error
    //Item* pointer = new Item;
    //unique_ptr<Item> item5 (pointer);
    //unique_ptr<Item> item6 (pointer);

    //разделяемый указатель (умный 2)
    shared_ptr<Item> item_1 = make_shared<Item> (12, 45.6);
    shared_ptr<Item> item_2 = item_1; // не создается объект??
    shared_ptr<Item> item_3 = make_shared<Item>();
    item_1 -> p= item_3;
    item_3 -> p = item_1;

    //Error
    // Item * pointer = new Item;
    // shared_ptr<Item> item_3(pointer);
    // shared_ptr<Item> item_4(pointer);


    return 0;
}