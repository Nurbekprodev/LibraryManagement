#include "User.hpp"
#include <sstream>
#include <stdexcept> // For runtime_error

User::User() {}

User::User(string u, string p, string r) {
    username = u;
    password = p;
    role = r;
}

string User::toLine() const {
    return username + "," + password + "," + role;
}

User User::fromLine(const string &line) {
    stringstream ss(line);
    string u, p, r;
    getline(ss, u, ',');
    getline(ss, p, ',');
    getline(ss, r, ',');

    // Validate extracted fields
    if (u.empty() || p.empty() || r.empty()) {
        throw runtime_error("Invalid user data format.");
    }

    return User(u, p, r);
}
