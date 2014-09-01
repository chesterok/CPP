#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <set>
#include <map>
#include "Category.h"
#include "Order.h"

class Category;
class Order;
class ItemsEnd{};

class Item {
    private:
        static std::set<Item*> items;
        std::map<Order*, int> orders;
        Category* category;
        std::string model;
        int counter;

    public:
        Item(Category* category, const std::string name, int counter=1);
        ~Item();

        const std::map<Order*, int>& getOrders() const;
        const Category* getCategory() const;
        const std::string& getName() const;
        static std::set<Item*>& getItems();
        int getCounter() const;
        void setCounter(int value);
        void addOrder(Order* newOrder, int quantity=1);
        void removeOrder(Order* oldOrder, int quantity=1);

        void changeCategory(Category* newCategory);
};

#endif // ITEM_H
