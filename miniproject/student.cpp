#pragma once

#include "student.h"
#include "course.h"

Student::Student(string id, string username, string password)
    : User(id, username, password, "Student") {
}

void Student::viewCourses() {
    cout << "Enrolled Courses:\n";
    for (auto course : enrolledCourses) {
        cout << course->getCourseName() << endl;
    }
}

void Student::addCourse(Course* course) {
    enrolledCourses.push_back(course);
    cout << "Course " << course->getCourseName() << " added to your list." << endl;
}

void Student::rateCourse(Course* course, int rating) {
    cout << "You rated the course " << course->getCourseName() << " with " << rating << " stars." << endl;
}

void Student::viewAssignments(Course* course) {
    cout << "Assignments for course " << course->getCourseName() << ":\n";
    // نمایش تکالیف
}

vector<Course*>  Student::getEnrolledCourses() const {
    return enrolledCourses;
}
