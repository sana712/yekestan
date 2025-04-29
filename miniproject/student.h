#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
class Course;

class Student : public User {
private:
    vector<Course*> enrolledCourses;

public:
    Student(string id, string username, string password);
    void viewCourses();

    void addCourse(Course* course);

    void rateCourse(Course* course, int rating);
    void viewAssignments(Course* course);
    vector<Course*> getEnrolledCourses() const;
    void enrollInCourse(Course* course);
    void viewGrades(const vector<Course*>& allCourses) const;

};
