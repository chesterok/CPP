#include "Category.h"

std::set<Category*> Category::categories(categories);

Category::Category(const std::string name) : name(name) {
    categories.insert(this);
}

Category::~Category() {
    categories.erase(this);
    std::map<Item*, int>::iterator it;

    for ( it = item.begin(); it != item.end(); it++  ) {
        it->first->changeCategory(NULL);
    }
}

std::map<Item*, int> Category::getItem() const {
    return item;
}

const std::string& Category::getName() const {
    return name;
}

 std::set<Category*>& Category::getCategories() {
    return categories;
 }

void Category::addItem(Item* newItem, int quantity) {
    if ( newItem->getCategory() != this ) {
        throw new BadCategory();
    }
    item[newItem] += quantity;
    newItem->setCounter(newItem->getCounter() + quantity);
}

void Category::removeItem(Item* oldItem, int quantity) {
    if ( oldItem->getCategory() != this ) {
        throw new BadCategory();
    }
    if ( item.find(oldItem)->second <= quantity ) {
        item.erase(oldItem);
        oldItem->changeCategory(NULL);
        return;
    }
    item[oldItem] -= quantity;
    oldItem->setCounter(oldItem->getCounter() - quantity);
}
