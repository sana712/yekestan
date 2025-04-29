#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "admin.h"
#include "instructor.h"
#include "student.h"

using namespace std;

class User {
protected:
    string id;
    string username;
    string password;
    string role;  // نقش کاربر (ادمین، استاد، دانشجو)

public:
    User(string id, string username, string password, string role);
    virtual void viewProfile();

    virtual void login();

    // Getter functions
    string getRole() const;

    string getUsername() const;

    string getId() const;

    string getPassword() const;

    // Setter functions
    void setRole(const string& newRole);

    void setUsername(const string& newUsername);

    void setId(const string& newId);

    void setPassword(const string& newPassword);
};
