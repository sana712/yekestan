#pragma once

#include <iostream>
#include <vector>
#include "student.h"
#include "instructor.h"
#include "admin.h"

#include "file.h"

using namespace std;



void studentMenu(Student* student) {
    int choice;
    do {
        cout << "\n=== Student Menu ===\n";
        cout << "1. View Enrolled Courses\n";
        cout << "2. Rate a Course\n";
        cout << "3. View Assignments\n";
        cout << "4. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            student->viewCourses();
            break;
        case 2: {
            int courseIndex, rating;
            cout << "Enter course index to rate (starting from 0): ";
            cin >> courseIndex;
            cout << "Enter your rating (1 to 5): ";
            cin >> rating;
            if (rating < 1 || rating > 5) {
                cout << "Invalid rating. Must be between 1 and 5.\n";
            }
            else {
                vector<Course*> courses = student->getEnrolledCourses();
                if (courseIndex >= 0 && courseIndex < courses.size()) {
                    student->rateCourse(courses[courseIndex], rating);
                }
                else {
                    cout << "Invalid course index.\n";
                }
            }
            break;
        }
        case 3: {
            int courseIndex;
            cout << "Enter course index to view assignments (starting from 0): ";
            cin >> courseIndex;
            vector<Course*> courses = student->getEnrolledCourses();
            if (courseIndex >= 0 && courseIndex < courses.size()) {
                student->viewAssignments(courses[courseIndex]);
            }
            else {
                cout << "Invalid course index.\n";
            }
            break;
        }
        case 4:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

        // ذخیره‌سازی دوره‌ها بعد از هر تغییر
        saveCoursesToFile(student->getEnrolledCourses());  // ذخیره‌سازی دوره‌های جدید
    } while (choice != 4);
}


//void instructorMenu(Instructor* instructor) {
//    int choice;
//    do {
//        cout << "\n=== Instructor Menu ===\n";
//        cout << "1. Create a Course\n";
//        cout << "2. Assign Grades\n";
//        cout << "3. Post Announcement\n";
//        cout << "4. View My Courses\n";
//        cout << "5. Logout\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            string courseId, courseName;
//            int capacity;
//
//            cout << "Enter course ID: ";
//            cin >> courseId;
//            cin.ignore();
//            cout << "Enter course name: ";
//            getline(cin, courseName);
//            cout << "Enter course capacity: ";
//            cin >> capacity;
//
//            Course* newCourse = new Course(courseId, courseName, instructor, capacity);
//            instructor->createCourse(newCourse);
//            saveCoursesToFile(instructor->getCourses());  // ذخیره‌سازی دوره‌ها بعد از ایجاد
//            cout << "Course created successfully.\n";
//            break;
//        }
//        case 2: {
//            instructor->assignGrades();
//            break;
//        }
//        case 3: {
//            instructor->postAnnouncement();
//            break;
//        }
//        case 4: {
//            instructor->viewCourses();
//            break;
//        }
//        case 5: {
//            cout << "Logging out...\n";
//            break;
//        }
//        default:
//            cout << "Invalid choice. Try again.\n";
//            break;
//        }
//   
//              // سایر موارد به همون صورت
//        
//    } while (choice != 5);
//}

void instructorMenu(Instructor* instructor) {
    int choice;
    do {
        cout << "\n=== Instructor Menu ===\n";
        cout << "1. Create a Course\n";
        cout << "2. Assign Grades\n";
        cout << "3. Post Announcement\n";
        cout << "4. View My Courses\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string courseId, courseName;
            int capacity;

            cout << "Enter course ID: ";
            cin >> courseId;
            cin.ignore();
            cout << "Enter course name: ";
            getline(cin, courseName);
            cout << "Enter course capacity: ";
            cin >> capacity;

            Course* newCourse = new Course(courseId, courseName, instructor, capacity);
            instructor->createCourse(newCourse);
            saveCoursesToFile(instructor->getCourses());  // ذخیره دوره‌ها به فایل بعد از ایجاد
            cout << "Course created successfully.\n";
            break;
        }
        case 2: {
            string courseId, studentId;
            int grade;

            cout << "Enter course ID: ";
            cin >> courseId;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter grade: ";
            cin >> grade;

            instructor->assignGrades(courseId, studentId, grade);
            break;
        }
        case 3: {
            string announcement;
            cout << "Enter announcement: ";
            cin.ignore();
            getline(cin, announcement);

            instructor->postAnnouncement(announcement);
            break;
        }
        case 4: {
            instructor->viewMyCourses();
            break;
        }
        case 5: {
            cout << "Logging out...\n";
            break;
        }
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice != 5);
}


void adminMenu(Admin* admin) {
    int choice;
    do {
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Create User\n";
        cout << "2. Delete User\n";
        cout << "3. Restore User\n";
        cout << "4. View Courses\n";
        cout << "5. View Statistics\n";
        cout << "6. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\n--- Create User ---\n";
            string id, username, password, role;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Role (Student / Instructor): ";
            cin >> role;

            User* newUser = nullptr;

            if (role == "Student") {
                newUser = new Student(id, username, password);
            }
            else if (role == "Instructor") {
                newUser = new Instructor(id, username, password);
            }
            else {
                cout << "Invalid role. User not created.\n";
                break;
            }

            admin->createUser(newUser);
            break;
        }
        case 2: {
            cout << "\n--- Delete User ---\n";
            string userId;
            cout << "Enter User ID to delete: ";
            cin >> userId;
            admin->deleteUser(userId);
            break;
        }
        case 3: {
            cout << "\n--- Restore User ---\n";
            string userId;
            cout << "Enter User ID to restore: ";
            cin >> userId;
            admin->restoreUser(userId);
            break;
        }
        case 4:
            cout << "\n--- View Course List ---\n";
            admin->viewCourseList();
            break;
        case 5:
            cout << "\n--- View Statistics ---\n";
            admin->viewStatistics();
            break;
        case 6:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

// تابع لاگین
bool login(const vector<User*>& users, string& role, User** loggedInUser) {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (const auto& user : users) {
        if (user->getUsername() == username && user->getPassword() == password) {
            role = user->getRole();
            *loggedInUser = user; // اینجا یوزر لاگین شده رو هم برمیگردونیم
            return true;
        }
    }
    return false;
}


 // حتما اینو داشته باش که توش save/load تعریف شده
#include "user.h" 
#include "course.h"
#include "assignment.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
  
    // اول کاربران را از فایل بارگذاری می‌کنیم
    vector<User*> users = loadUsersFromFile();
   /* cout << "Users loaded: " << users.size() << endl;
    for (User* user : users) {
        cout << user->getUsername() << " (" << user->getRole() << ")" << endl;
    }*/

    vector<Instructor*> instructors;
    for (User* user : users) {
        if (user->getRole() == "Instructor") {
            instructors.push_back(dynamic_cast<Instructor*>(user));
        }
    }

    // بعد از لود یوزرها، حالا لود درس‌ها
    vector<Course*> allCourses = loadCoursesFromFile(instructors);

    // نسبت دادن درس‌ها به استاد مربوطه
    for (Course* course : allCourses) {
        Instructor* prof = course->getProfessor();
        if (prof != nullptr) {
            prof->addCourse(course);
        }
    }

    if (users.empty()) {
        cout << "No users found. Exiting program." << endl;
        return 0;
    }
 

    string role;
    User* loggedInUser = nullptr;

    if (login(users, role, &loggedInUser)) { // تغییر دادم تا یوزر لاگین‌شده هم داشته باشیم
        cout << "Login successful. Role: " << role << endl;

        if (role == "Student") {
            Student* student = dynamic_cast<Student*>(loggedInUser);
            if (student) {
                studentMenu(student);
            }
        }
        else if (role == "Instructor") {
            Instructor* instructor = dynamic_cast<Instructor*>(loggedInUser);
            if (instructor) {
                instructorMenu(instructor);
            }
        }
        else if (role == "Admin") {
            Admin* admin = dynamic_cast<Admin*>(loggedInUser);
            if (admin) {
                adminMenu(admin);
            }
        }
    }
    else {
        cout << "Invalid username or password.\n";
    }

    // بعد از پایان برنامه، کاربران رو دوباره ذخیره می‌کنیم
    saveUsersToFile(users);

    // پاک کردن حافظه داینامیک
    for (auto user : users) {
        delete user;
    }

    return 0;
}
