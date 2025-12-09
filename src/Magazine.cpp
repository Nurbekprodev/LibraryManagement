#include "Magazine.hpp"
#include <stdexcept> // For runtime_error

Magazine::Magazine(int id, string title, int issue, int count)
    : Item(id, title, count), issueNumber(issue) {
    if (id <= 0 || title.empty() || issue <= 0 || count < 0) {
        throw runtime_error("Invalid magazine data. Ensure ID, title, issue number, and count are valid.");
    }
}

void Magazine::display() const {
    cout << "[Magazine] ID: " << id
         << " | Title: " << title
         << " | Issue: " << issueNumber
         << " | Available: " << availableCount
         << "\n";
}

string Magazine::serialize() const {
    return "MAGAZINE," + to_string(id) + "," + title + "," +
           to_string(issueNumber) + "," + to_string(availableCount);
}
