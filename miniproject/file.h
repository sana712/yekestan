#pragma once
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <vector>
#include "user.h"
#include"admin.h"
#include "course.h"
#include "assignment.h"


using namespace std;

// ذخیره‌سازی و بارگذاری کاربران
void saveUsersToFile(std::vector<User*> users);
vector<User*> loadUsersFromFile();

// ذخیره‌سازی و بارگذاری دروس
void saveCoursesToFile(std::vector<Course*> courses);
std::vector<Course*> loadCoursesFromFile(std::vector<Instructor*> instructors);

vector<Instructor*> loadInstructorsFromFile();
// ذخیره‌سازی و بارگذاری تکالیف
void saveAssignmentsToFile(std::vector<Assignment*> assignments);
std::vector<Assignment*> loadAssignmentsFromFile();


void loadStudentCourses(vector<User*>& users, const vector<Course*>& allCourses);
void saveStudentCourses(const vector<User*>& users);

#endif
