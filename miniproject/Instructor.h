#pragma once
#include "user.h"

#include <iostream>
#include <string>
#include <vector>

class Course;


using namespace std;

class Instructor : public User {
private:
    vector<Course*> courses;

public:
    Instructor(string id, string username, string password);

    void createCourse(Course* newCourse);

    void assignGrades(string courseId, string studentId, int grade);
    void postAnnouncement(string announcement);
    void viewMyCourses();
};
