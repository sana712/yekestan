#include "Instructor.h"
#include"course.h"


Instructor::Instructor(string id, string username, string password)
    : User(id, username, password, "Instructor") {
}

void Instructor::createCourse(Course* newCourse) {
    courses.push_back(newCourse);
    cout << "Course " << newCourse->getCourseName() << " created successfully." << endl;
}

void Instructor::assignGrades(string courseId, string studentId, int grade) {
    bool found = false;

    for (Course* course : courses) {
        if (course->getCourseId() == courseId) {
            found = true;
            // اینجا چون ارتباط مستقیم با دانشجوها نداری، فعلاً فقط نمره به درس اضافه می‌کنیم
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
            cout << "- " << course->getCourseName() << " (ID: " << course->getCourseId() << ")\n";
        }
    }
}