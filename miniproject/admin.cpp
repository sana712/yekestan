#include "admin.h"


Admin :: Admin(string id, string username, string password)
    : User(id, username, password, "Admin") {
}

void Admin::createUser(User* newUser) {
    users.push_back(newUser);
    cout << "User " << newUser->getRole() << " created successfully." << endl;
}

void Admin::deleteUser(string userId) {
    // Soft delete (حذف نرم)
    cout << "User with ID " << userId << " deleted (soft delete)." << endl;
}

void Admin::restoreUser(string userId) {
    cout << "User with ID " << userId << " restored." << endl;
}

void Admin::viewCourseList() {
    for (auto course : courses) {
        cout << "Course ID: " << course->getCourseId() << ", Name: " << course->getCourseName() << endl;
    }
}

void Admin::viewStatistics() {
    // نمایش آمار کلی از دروس
    for (auto course : courses) {
        cout << "Course: " << course->getCourseName() << ", Avg Grade: " << course->getAverageGrade() << endl;
    }
}