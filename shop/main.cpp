#include <iostream>
#include <set>
#include "Item.h"
#include "Category.h"
#include "Order.h"
#include "templates.cpp"
#include "Customer.h"

using namespace std;

int main() {
    Category* mobile = new Category("Mobile");
    Item* iphone = new Item(mobile, "iphone");
    Item* nokia = new Item(mobile, "nokia");
    Item* samsung4 = new Item(mobile, "samsung");
    Item* iphone1 = new Item(mobile, "iphone1");
    Item* nokia2 = new Item(mobile, "nokia2");
    Item* samsung3 = new Item(mobile, "samsung3", 3);
    Customer* customer = new Customer("Yuriy");
    Customer* customer1 = new Customer("Yuriy1");
    Order* order = new Order(customer, samsung3, "order#1");
    Order* order2 = new Order(customer, samsung3, "order#2");
    cout << Category::getCategories() << endl;
    cout << Customer::getCustomers() << endl;
    cout << Item::getItems() << endl;
    cout << Order::getOrders() << endl;

    order->addItem(nokia);

    cout << order->getItem() << endl;
    delete mobile;

    Order* order3 = new Order(customer, samsung3, "order#3");

    cout << nokia->getOrders() << endl;
    cout << customer->getOrders() << endl;

    cout << Item::getItems() << endl;



    return 0;
}
