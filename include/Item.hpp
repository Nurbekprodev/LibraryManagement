#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    int id;
    string title;
    int availableCount; // Number of available items

public:
    Item(int id, string title, int count);
    virtual ~Item() {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    int getAvailableCount() const { return availableCount; }
    void setAvailableCount(int count) { availableCount = count; }

    virtual string serialize() const = 0;
    virtual void display() const = 0;
};

#endif
