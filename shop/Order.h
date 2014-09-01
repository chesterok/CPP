#ifndef ORDER_H
#define ORDER_H

#include "Item.h"
#include "Customer.h"
#include <iostream>
#include <map>

class Item;
class Customer;

class Order {
    private:
        static std::set<Order*> orders;
        Customer* customer;
        std::map<Item*, int> item;
        std::string nameOrder;

    public:
        Order(Customer* customer, Item* item, const std::string nameOrder);
        ~Order();

        const std::map<Item*, int>& getItem() const;
        const std::string& getName() const;
        Customer* getCustomer() const;
        static std::set<Order*>& getOrders();
        void removeSelf();
        void addItem(Item* newItem, int quantity=1);
        void removeItem(Item* oldItem, int quantity=1);
};

#endif // ORDER_H
