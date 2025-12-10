#ifndef BORROW_RECORD_HPP
#define BORROW_RECORD_HPP

#include <string>
using namespace std;

class BorrowRecord {
public:
    int itemId;
    string memberName;

    BorrowRecord(int id, string member); //constructor 
    string serialize() const;
};

#endif
