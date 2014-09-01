#include "Item.h"

std::set<Item*> Item::items(items);

Item::Item(Category* category, const std::string model, int counter) : model(model), category(category) {
    this->counter = 0;
    category->addItem(this, counter);
    items.insert(this);
}

Item::~Item() {
    items.erase(this);
    
    Category* newCategory = category;

    std::cout << this->getName() << " destroy3d..." << std::endl;
    category = NULL;
    if ( newCategory == NULL ) {
        newCategory->removeItem(this);
    }

    std::map<Order*, int>::iterator it;

    for ( it = orders.begin(); it != orders.end(); it++ ) {
        it->first->removeItem(this);
    }
}

void Item::setCounter(int value) {
    if ( value < 0 ) {
        throw new ItemsEnd();
    }
    counter = value;
}

 std::set<Item*>& Item::getItems() {
    return items;
 }

void Item::addOrder(Order* newOrder, int quantity) {
    orders[newOrder] += quantity;
}

void Item::removeOrder(Order* oldOrder, int quantity) {
    if ( orders.find(oldOrder)->second - quantity <= 0 ) {
        orders.erase(oldOrder);
    } else {
        orders[oldOrder] -= quantity;
    }
}

const Category* Item::getCategory() const {
    return category;
}

int Item::getCounter() const {
    return counter;
}

const std::string& Item::getName() const {
    return model;
}

const std::map<Order*, int>& Item::getOrders() const {
    return orders;
}

void Item::changeCategory(Category* newCategory) {
    if ( newCategory == category ) {
        return;
    }
    if ( newCategory == NULL ) {
        delete this;
        return;
    }
    category->removeItem(this);
    newCategory->addItem(this);
    category = newCategory;
}
