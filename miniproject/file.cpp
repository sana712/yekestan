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
            outFile << course->getCourseId() << ","
                << course->getCourseName() << ","
                << course->getProfessor()->getId() << ","
                << course->getCapacity();

            // حالا ذخیره‌ی studentIds و grades
            vector<string> studentIds = course->getStudentIds(); // فرض گرفتم همچین تابعی داری
            vector<double> grades = course->getGrades();         // فرض گرفتم همچین تابعی داری

            if (!studentIds.empty()) {
                outFile << "|";
                for (int i = 0; i < studentIds.size(); i++) {
                    outFile << studentIds[i] << ":" << grades[i];
                    if (i != studentIds.size() - 1)
                        outFile << ",";
                }
            }

            outFile << endl;
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
        cout << "Error opening course file!" << endl;
        return courses;
    }

    while (getline(inFile, line)) {
        size_t pipePos = line.find("|");

        // قسمت اول: اطلاعات درس
        string courseInfo = line.substr(0, pipePos);
        size_t pos1 = courseInfo.find(",");
        string courseId = courseInfo.substr(0, pos1);
        size_t pos2 = courseInfo.find(",", pos1 + 1);
        string courseName = courseInfo.substr(pos1 + 1, pos2 - pos1 - 1);
        size_t pos3 = courseInfo.find(",", pos2 + 1);
        string professorId = courseInfo.substr(pos2 + 1, pos3 - pos2 - 1);
        int capacity = stoi(courseInfo.substr(pos3 + 1));

        // پیدا کردن استاد
        Instructor* instructor = nullptr;
        for (auto inst : instructors) {
            if (inst->getId() == professorId) {
                instructor = inst;
                break;
            }
        }

        if (instructor == nullptr) continue; // اگر استاد پیدا نشد بیخیال این درس شو

        Course* course = new Course(courseId, courseName, instructor, capacity);

        // قسمت دوم: اطلاعات دانشجوها و نمره‌ها
        if (pipePos != string::npos && pipePos + 1 < line.length()) {
            string studentsInfo = line.substr(pipePos + 1);
            stringstream ss(studentsInfo);
            string token;
            while (getline(ss, token, ',')) {
                size_t colonPos = token.find(":");
                string studentId = token.substr(0, colonPos);
                double grade = stod(token.substr(colonPos + 1));

                // ایجاد شیء موقت برای دانشجو (بسته به پیاده‌سازیت میشه اینجا بهترش هم کرد)
                Student* student = new Student(studentId, "", "");  // فقط آی‌دی لازمه
                course->enrollStudent(studentId);  // اضافه کردن دانشجو
                course->addGrade(grade);          // اضافه کردن نمره
            }
        }

        courses.push_back(course);
    }

    inFile.close();
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

void saveStudentCourses(const vector<User*>& users) {
    ofstream outFile("students_courses.txt");
    if (!outFile) {
        cout << "Error opening file to save student courses.\n";
        return;
    }

    for (User* user : users) {
        Student* student = dynamic_cast<Student*>(user);
        if (student) {
            outFile << student->getId();
            for (Course* course : student->getEnrolledCourses()) {
                outFile << "," << course->getCourseId();
            }
            outFile << endl;
        }
    }

    outFile.close();
}

void loadStudentCourses(vector<User*>& users, const vector<Course*>& allCourses) {
    ifstream inFile("students_courses.txt");
    if (!inFile) {
        cout << "No student courses file found.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ',');

        Student* student = nullptr;
        for (User* user : users) {
            student = dynamic_cast<Student*>(user);
            if (student && student->getId() == id) {
                break;
            }
        }

        if (student) {
            string courseId;
            while (getline(ss, courseId, ',')) {
                for (Course* course : allCourses) {
                    if (course->getCourseId() == courseId) {
                        student->  enrollInCourse(course); // اضافه کردن درس به دانشجو
                    }
                }
            }
        }
    }

    inFile.close();
}
