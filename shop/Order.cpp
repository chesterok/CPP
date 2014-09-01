#include "Order.h"

std::set<Order*> Order::orders(orders);

Order::Order(Customer* customer, Item* item, const std::string nameOrder) : 
nameOrder(nameOrder), customer(customer)
{
    orders.insert(this);
    this->addItem(item);
    this->customer->addOrder(this);
}

Order::~Order() {
    orders.erase(this);
    std::map<Item*, int>::iterator it;

    for ( it = item.begin(); it != item.end(); it++ ) {
        std::cout << "Delete: " << it->first->getName() << std::endl;
        it->first->removeOrder(this, item.find(it->first)->second);
    }
    customer->removeOrder(this);
}

const std::map<Item*, int>& Order::getItem() const {
    return item;
}

const std::string& Order::getName() const {
    return nameOrder;
}

Customer* Order::getCustomer() const {
    return customer;
}

std::set<Order*>& Order::getOrders() {
    return orders;
}

void Order::addItem(Item* newItem, int quantity) {
    newItem->setCounter(newItem->getCounter() - quantity);
    item[newItem] += quantity;
    newItem->addOrder(this, quantity);
}

void Order::removeItem(Item* oldItem, int quantity) {
    int keyValue = item.find(oldItem)->second;

    item.erase(oldItem);
    oldItem->removeOrder(this, quantity);
    oldItem->setCounter(oldItem->getCounter() + keyValue);

    if ( item.size() == 0 ) {
        oldItem->removeOrder(this, oldItem->getOrders().find(this)->second);
        delete this;
    }
}
