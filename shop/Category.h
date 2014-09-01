#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <map>
#include "Item.h"

class Item;
class BadCategory {};

class Category {
    private:
        static std::set<Category*> categories;
        std::string name;
        std::map<Item*, int> item;
    public:
        Category(const std::string name);
        ~Category();

        std::map<Item*, int> getItem() const;
        const std::string& getName() const;
        static std::set<Category*>& getCategories();
        void addItem(Item* newItem, int quantity=1);
        void removeItem(Item* oldItem, int quantity=1);
};

#endif // CATEGORY_H
