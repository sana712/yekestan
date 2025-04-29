#pragma once

#include "student.h"
#include "course.h"
#include <iostream>
using namespace std;

Student::Student(string id, string username, string password)
    : User(id, username, password, "Student") {
}

void Student::viewCourses() {
    cout << "\n=== Enrolled Courses ===\n";
    if (enrolledCourses.empty()) {
        cout << "You have not enrolled in any courses yet.\n";
    }
    else {
        for (auto course : enrolledCourses) {
            cout << "- " << course->getCourseName() << " (ID: " << course->getCourseId() << ")\n";
        }
    }
}

void Student::addCourse(Course* course) {
    enrolledCourses.push_back(course);
    cout << "Course \"" << course->getCourseName() << "\" added to your enrolled list." << endl;
    // ذخیره در فایل اینجا زده نمی‌شود - باید بیرون از این تابع انجام شود
}

void Student::rateCourse(Course* course, int rating) {
    cout << "You rated the course \"" << course->getCourseName() << "\" with " << rating << " stars." << endl;
    // (میتوانی بعدها ریتینگ را در کورس ذخیره هم بکنی)
}

void Student::viewAssignments(Course* course) {
    cout << "\nAssignments for course \"" << course->getCourseName() << "\":\n";
    // در آینده اینجا میتوانی یک لیست واقعی از تکالیف چاپ کنی
}

vector<Course*> Student::getEnrolledCourses() const {
    return enrolledCourses;
}
