#include "file.h"
#include "user.h"
#include <fstream>
#include <iostream>
#include <sstream>

// تابع ذخیره اطلاعات کاربران در فایل
void saveUsersToFile(vector<User*> users) {
    ofstream outFile("D:\\ap.cpp\\miniproject\\users.txt", ios::out);
    if (outFile.is_open()) {
        for (auto user : users) {
            outFile << user->getRole() << "," << user->getId() << "," << user->getUsername() << "," << user->getPassword() << endl;
        }
        outFile.close();
        cout << "Users saved to file." << endl;
    }
    else {
        cout << "Error opening file for saving users." << endl;
    }
}

// تابع بارگذاری کاربران از فایل
vector<User*> loadUsersFromFile() {
    vector<User*> users;
    ifstream inFile("D:\\ap.cpp\\miniproject\\users.txt", ios::in);
    string line;

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return users;
    }

    while (getline(inFile, line)) {
        size_t pos1 = line.find(",");
        string role = line.substr(0, pos1);
        size_t pos2 = line.find(",", pos1 + 1);
        string id = line.substr(pos1 + 1, pos2 - pos1 - 1);
        size_t pos3 = line.find(",", pos2 + 1);
        string username = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string password = line.substr(pos3 + 1);

        if (role == "Student") {
            users.push_back(new Student(id, username, password));
        }
        else if (role == "Instructor") {
            users.push_back(new Instructor(id, username, password));
        }
        else if (role == "Admin") {
            users.push_back(new Admin(id, username, password));
        }
        else {
            // نقش ناشناخته، ردش کن
            cout << "Unknown role found in file: " << role << endl;
        }
    }

    inFile.close();
    return users;
}

// تابع ذخیره دروس به فایل
void saveCoursesToFile(vector<Course*> courses) {
    ofstream outFile("D:\\ap.cpp\\miniproject\\course.txt", ios::out);
    if (outFile.is_open()) {
        for (auto course : courses) {
            outFile << course->getCourseId() << "," << course->getCourseName() << "," << course->getProfessor()->getId() << "," << course->getCapacity() << endl;
        }
        outFile.close();
        cout << "Courses saved to file." << endl;
    }
    else {
        cout << "Error opening file for saving courses." << endl;
    }
}

// تابع بارگذاری استادان از فایل
vector<Instructor*> loadInstructorsFromFile() {
    vector<Instructor*> instructors;
    ifstream inFile("D:\\ap.cpp\\miniproject\\users.txt", ios::in);  // بارگذاری استادان از همون فایل کاربران
    string line;

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return instructors;
    }

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            size_t pos1 = line.find(",");
            string role = line.substr(0, pos1);
            size_t pos2 = line.find(",", pos1 + 1);
            string id = line.substr(pos1 + 1, pos2 - pos1 - 1);

            if (role == "Instructor") {  // فقط استادان رو بارگذاری می‌کنیم
                size_t pos3 = line.find(",", pos2 + 1);
                string username = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string password = line.substr(pos3 + 1);
                instructors.push_back(new Instructor(id, username, password));
            }
        }
        inFile.close();
    }
    else {
        cout << "Error opening file for loading instructors." << endl;
    }

    return instructors;
}

// تابع بارگذاری دوره‌ها از فایل
vector<Course*> loadCoursesFromFile(vector<Instructor*> instructors) {
    vector<Course*> courses;
    ifstream inFile("D:\\ap.cpp\\miniproject\\course.txt", ios::in);
    string line;

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return courses;
    }

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            size_t pos1 = line.find(",");
            string courseId = line.substr(0, pos1);
            size_t pos2 = line.find(",", pos1 + 1);
            string courseName = line.substr(pos1 + 1, pos2 - pos1 - 1);
            size_t pos3 = line.find(",", pos2 + 1);
            string professorId = line.substr(pos2 + 1, pos3 - pos2 - 1);
            int capacity = stoi(line.substr(pos3 + 1));

            // پیدا کردن استاد با آی‌دی
            Instructor* instructor = nullptr;
            for (auto inst : instructors) {
                if (inst->getId() == professorId) {
                    instructor = inst;
                    break;
                }
            }

            if (instructor != nullptr) {
                courses.push_back(new Course(courseId, courseName, instructor, capacity));
            }
        }
        inFile.close();
    }
    else {
        cout << "Error opening file for loading courses." << endl;
    }

    return courses;
}

void printUsersFromFile() {
    ifstream inFile("D:\\ap.cpp\\miniproject\\users.txt", ios::in);
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "Error opening file for printing users." << endl;
    }
}
