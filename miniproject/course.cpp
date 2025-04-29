#include "course.h"

Course::Course(std::string id, std::string name, Instructor* prof, int cap)
    : courseId(id), courseName(name), professor(prof), capacity(cap) {
}

// Getters و setters
std::string Course::getCourseId() const { return courseId; }
void Course::setCourseId(const std::string& id) { courseId = id; }

std::string Course::getCourseName() const { return courseName; }
void Course::setCourseName(const std::string& name) { courseName = name; }

Instructor* Course::getProfessor() const { return professor; }
void Course::setProfessor(Instructor* prof) { professor = prof; }

int Course::getCapacity() const { return capacity; }
void Course::setCapacity(int cap) { capacity = cap; }

double Course::getAverageGrade() const {
    if (grades.empty()) return 0.0;
    double sum = 0;
    for (double grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}
void Course::addGrade(double grade) {
    grades.push_back(grade);  // نمره رو به لیست نمرات اضافه می‌کنه
}

void Course::addAssignment(const string& assignment) {
    assignments.push_back(assignment);
}
void Course::viewAssignments() const {
    if (assignments.empty()) {
        cout << "No assignments for this course.\n";
    }
    else {
        cout << "Assignments:\n";
        for (const auto& a : assignments) {
            cout << "- " << a << endl;
        }
    }
}

void Course::setGradeForStudent(const string& studentId, double grade) {
    for (int i = 0; i < studentIds.size(); i++) {
        if (studentIds[i] == studentId) {
            grades[i] = grade; // اگر قبلاً داشت، نمره رو آپدیت کن
            return;
        }
    }
    // اگر دانشجو پیدا نشد، اضافه کن
    studentIds.push_back(studentId);
    grades.push_back(grade);
}

void Course::enrollStudent(const string& studentId) {
    if (studentIds.size() >= capacity) {
        cout << "Course is full. Cannot enroll more students.\n";
        return;
    }
    studentIds.push_back(studentId);
    grades.push_back(-1); // دانشجو ثبت نام شد، نمره اولیه -1
}

// گرفتن نمره‌ی دانشجو
double Course::getGradeForStudent(const string& studentId) const {
    for (int i = 0; i < studentIds.size(); i++) {
        if (studentIds[i] == studentId) {
            return grades[i];
        }
    }
    return -1; // یعنی نمره‌ای وجود نداره
}


vector<string> Course::getStudentIds() const {
    return studentIds;
}

vector<double> Course::getGrades() const {
    return grades;
}