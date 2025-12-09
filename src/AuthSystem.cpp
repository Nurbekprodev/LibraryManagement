#include "AuthSystem.hpp"
#include <fstream>
#include <iostream>

AuthSystem::AuthSystem(string file) {
    filename = file;
    loadUsers();
}

void AuthSystem::loadUsers() {
    users.clear();
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        users.push_back(User::fromLine(line));
    }
}

void AuthSystem::saveUsers() {
    ofstream file(filename);
    for (auto &u : users) {
        file << u.toLine() << "\n";
    }
}

bool AuthSystem::signup(const string &username, const string &password, const string &role) {
    if (username.empty() || password.empty() || (role != "admin" && role != "user")) {
        throw AuthException("Invalid input. Ensure username, password, and role are valid.");
    }

    for (auto &u : users) {
        if (u.username == username)
            throw AuthException("Username already exists!");
    }
    User newUser(username, password, role);
    users.push_back(newUser);
    saveUsers();
    return true;
}

User AuthSystem::login(const string &username, const string &password) {
    if (username.empty() || password.empty()) {
        throw AuthException("Invalid input. Username and password cannot be empty.");
    }

    for (auto &u : users) {
        if (u.username == username && u.password == password)
            return u;
    }
    throw AuthException("Invalid username or password!");
}
