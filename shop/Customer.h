#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <iostream>
#include <set>

class Order;
class InvalidCustomer{};

class Customer {
    private:
        static std::set<Customer*> customers;
        std::set<Order*> orders;
        std::string name;

    public:
        Customer(const std::string name);
        ~Customer();

        const std::set<Order*>& getOrders() const;
        const std::string& getName() const;
        static std::set<Customer*>& getCustomers();
        void addOrder(Order* newOrder);
        void removeOrder(Order* oldOrder);

};

#endif // CUSTOMER_H
