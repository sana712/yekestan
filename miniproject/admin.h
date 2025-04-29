#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "course.h"
#include"file.h"

class Admin : public User {
private:
    vector<User*> users;
    vector<Course*> courses;

public: 
    Admin(string id, string username, string password)
        : User(id, username, password, "Admin") {
    }

    void createUser(User* newUser) {
        users.push_back(newUser);
        cout << "User " << newUser->getRole() << " created successfully." << endl;
    }

    void deleteUser(string userId) {
        // Soft delete (حذف نرم)
        cout << "User with ID " << userId << " deleted (soft delete)." << endl;
    }

    void restoreUser(string userId) {
        cout << "User with ID " << userId << " restored." << endl;
    }

    void viewCourseList() {
        for (auto course : courses) {
            cout << "Course ID: " << course->getCourseId() << ", Name: " << course->getCourseName() << endl;
        }
    }

    void viewStatistics() {
        // نمایش آمار کلی از دروس
        for (auto course : courses) {
            cout << "Course: " << course->getCourseName() << ", Avg Grade: " << course->getAverageGrade() << endl;
        }
    }
};
