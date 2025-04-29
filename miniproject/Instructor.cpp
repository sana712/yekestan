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


// نمونه ذخیره‌سازی نمره در فایل
void Instructor::assignGrades(string courseId, string studentId, int grade) {
    // جستجو برای دوره و دانشجو
    for (Course* course : courses) {
        if (course->getCourseId() == courseId) {
            course->setGradeForStudent(studentId, grade);
            saveCoursesToFile(courses);  // ذخیره تغییرات به فایل
            cout << "Assigned grade " << grade << " to student " << studentId << " in course " << course->getCourseName() << endl;
            break;
        }
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

void Instructor::displayGradeForStudent(const string& studentId) const {
    for (const auto& course : courses) {
        double grade = course->getGradeForStudent(studentId);
        if (grade != -1) {
            cout << "Grade for student " << studentId << " in course " << course->getCourseName() << ": " << grade << endl;
        }
        else {
            cout << "No grade assigned for student " << studentId << " in course " << course->getCourseName() << endl;
        }
    }
}
