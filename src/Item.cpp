#include "Item.hpp"       // Include the header for the Item class
#include <stdexcept>      // For std :: runtime_error

// Constructor for Item; initializes id, title, and availableCount
Item::Item(int id, std::string title, int count) : id(id), title(title), availableCount(count) {

    // Validate input: ID must be positive, title must not be empty, count cannot be negative
    if (id <= 0 || title.empty() || count < 0) {
        throw std::runtime_error("Invalid item data. Ensure ID, title, and count are valid.");
    }
}
