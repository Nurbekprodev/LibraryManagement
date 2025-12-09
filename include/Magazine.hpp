#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include "Item.hpp"
using namespace std;

class Magazine : public Item {
    int issueNumber;

public:
    Magazine(int id, string title, int issue, int count);
    void display() const override;
    string serialize() const override;
};

#endif
