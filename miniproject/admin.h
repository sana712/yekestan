#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "course.h"


class Admin : public User {
private:
    vector<User*> users;
    vector<Course*> courses;

public: 
    Admin(string id, string username, string password);
    void createUser(User* newUser);

    void deleteUser(vector<User*>& users, const string& userId);

    void restoreUser(string userId);

    void viewCourseList();

    void viewStatistics();
    void createUser(vector<User*>& users, User* newUser);
};
