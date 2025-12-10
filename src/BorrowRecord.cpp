#include "BorrowRecord.hpp"    // Include the header file for the BorrowRecord class

// Constructor for BorrowRecord ; initializes itemId and memberName
BorrowRecord::BorrowRecord(int id, string member)
    : itemId(id), memberName(member) {}

// Serialize the borrow record into a single string: "itemId,memberName"
string BorrowRecord::serialize() const {
    return to_string(itemId) + "," + memberName;
}
