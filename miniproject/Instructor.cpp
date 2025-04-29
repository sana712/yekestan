#include "Instructor.h"
#include"course.h"
#include "file.h"


Instructor::Instructor(string id, string username, string password)
    : User(id, username, password, "Instructor") {
   
}


void Instructor::createCourse(Course* newCourse) {
    courses.push_back(newCourse);
    saveCoursesToFile(courses);  // ذخیره به فایل
    cout << "Course " << newCourse->getCourseName() << " created successfully." << endl;
}


void Instructor::assignGrades(string courseId, string studentId, int grade) {
    bool found = false;

    for (Course* course : courses) {
        if (course->getCourseId() == courseId) {
            found = true;
            // اضافه کردن نمره به درس
            course->addGrade(grade);
            saveCoursesToFile(courses);  // ذخیره به فایل بعد از تغییر
            cout << "Assigned grade " << grade << " to student " << studentId << " in course " << course->getCourseName() << endl;
            break;
        }
    }

    if (!found) {
        cout << "Course not found!\n";
    }
}


void Instructor::postAnnouncement(string announcement) {
    cout << "Announcement posted: " << announcement << endl;
}

void Instructor::viewMyCourses() {
    cout << "\n=== My Courses ===\n";
    if (courses.empty()) {
        cout << "You have not created any courses yet.\n";
    }
    else {
        for (Course* course : courses) {
            cout << "- " << course->getCourseName() << " (ID: " << course->getCourseId() << ")" << endl;
        }
    }
}

void Instructor::addCourse(Course* course) {
    courses.push_back(course);
}

// گرفتن دوره‌های استاد
vector<Course*> Instructor::getCourses() const {
    return courses;
}

