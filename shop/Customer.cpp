#include "Customer.h"

std::set<Customer*> Customer::customers(customers);

Customer::Customer(const std::string name) : name(name) {
    customers.insert(this);
}

Customer::~Customer() {
    customers.erase(this);

    std::set<Order*>::iterator it;

    for ( it = orders.begin(); it != orders.end(); it++ ) {
        std::cout << (*it)->getName() << " deleted..." << std::endl;
        delete *it;
    }
}

const std::set<Order*>& Customer::getOrders() const {
    return orders;
}

 std::set<Customer*>& Customer::getCustomers() {
    return customers;
 }

const std::string& Customer::getName() const {
    return name;
}

void Customer::addOrder(Order* newOrder) {
    if ( newOrder->getCustomer() != this ) {
        throw new InvalidCustomer();
    }
    orders.insert(newOrder);
}

void Customer::removeOrder(Order* oldOrder) {
    if ( oldOrder->getCustomer() == this ) {
        orders.erase(oldOrder);
    }
}
