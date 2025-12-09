#include <fstream>
#include <sstream>
#include <stdexcept> // For runtime_error
#include "Library.hpp"
#include "Book.hpp"
#include "Magazine.hpp"

void Library::addItem(shared_ptr<Item> item) {
    catalog.push_back(item);
}

void Library::displayCatalog() const {
    for (auto &i : catalog)
        i->display();
}

void Library::borrowItem(int id, const string &member) {
    if (member.empty()) {
        throw runtime_error("Member name cannot be empty.");
    }

    for (auto &i : catalog) {
        if (i->getId() == id) {
            if (i->getAvailableCount() <= 0)
                throw runtime_error("Item not available for borrowing.");

            i->setAvailableCount(i->getAvailableCount() - 1);
            records.emplace_back(id, member);
            cout << "Borrow successful.\n";
            return;
        }
    }
    throw ItemNotFoundException("Item not found!");
}

void Library::returnItem(int id) {
    for (auto &i : catalog) {
        if (i->getId() == id) {
            i->setAvailableCount(i->getAvailableCount() + 1);
            cout << "Item returned.\n";
            return;
        }
    }
    throw ItemNotFoundException("Item not found!");
}

void Library::save() {
    ofstream cat("data/catalog.txt");
    for (auto &i : catalog)
        cat << i->serialize() << "\n";

    ofstream rec("data/records.txt");
    for (auto &r : records)
        rec << r.serialize() << "\n";
}

void Library::load() {
    ifstream cat("data/catalog.txt");
    string line;

    while (getline(cat, line)) {
        stringstream ss(line);
        string type, title, extra, available;
        int id;

        getline(ss, type, ',');
        ss >> id; ss.ignore();
        getline(ss, title, ',');
        getline(ss, extra, ',');
        getline(ss, available, ',');

        if (type == "BOOK") {
            auto b = make_shared<Book>(id, title, extra, stoi(available));
            catalog.push_back(b);
        }
        else if (type == "MAGAZINE") {
            auto m = make_shared<Magazine>(id, title, stoi(extra), stoi(available));
            catalog.push_back(m);
        }
    }

    ifstream rec("data/records.txt");
    while (getline(rec, line)) {
        stringstream ss(line);
        int id;
        string member;

        ss >> id; ss.ignore();
        getline(ss, member);
        records.emplace_back(id, member);
    }
}
