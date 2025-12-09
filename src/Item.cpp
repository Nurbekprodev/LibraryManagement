#include "Item.hpp"
#include <stdexcept> // For runtime_error

Item::Item(int id, std::string title, int count) : id(id), title(title), availableCount(count) {
    if (id <= 0 || title.empty() || count < 0) {
        throw std::runtime_error("Invalid item data. Ensure ID, title, and count are valid.");
    }
}