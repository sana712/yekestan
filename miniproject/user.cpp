#pragma once


#include "user.h"

using namespace std;
User::User(string id, string username, string password, string role)
    : id(id), username(username), password(password), role(role) {
}

 void User::viewProfile() {
    cout << "ID: " << id << "\nUsername: " << username << "\nRole: " << role << endl;
}

 void User::login() {
    cout << "Logging in user: " << username << endl;
}

// Getter functions
string User::getRole() const {
    return role;
}

string User::getUsername() const {
    return username;
}

string User::getId() const {
    return id;
}

string User::getPassword() const {
    return password;
}

// Setter functions
void User::setRole(const string& newRole) {
    role = newRole;
}

void User::setUsername(const string& newUsername) {
    username = newUsername;
}

void User::setId(const string& newId) {
    id = newId;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}