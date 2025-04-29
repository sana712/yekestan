#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "Instructor.h"
#include "student.h"
#include "assignment.h"


#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "User.h"

    class Course {
    private:
        std::string courseId;
        std::string courseName;
        Instructor* professor;
        int capacity;
        vector<string> studentIds;    // لیست آیدی دانشجوها
        vector<double> grades;
        vector<string> assignments;

    public:
        Course(std::string id, std::string name, Instructor* prof, int cap)
            : courseId(id), courseName(name), professor(prof), capacity(cap) {
        }

        // Getters و setters
        std::string getCourseId() const { return courseId; }
        void setCourseId(const std::string& id) { courseId = id; }

        std::string getCourseName() const { return courseName; }
        void setCourseName(const std::string& name) { courseName = name; }

        Instructor* getProfessor() const { return professor; }
        void setProfessor(Instructor* prof) { professor = prof; }

        int getCapacity() const { return capacity; }
        void setCapacity(int cap) { capacity = cap; }

        double getAverageGrade() const {
            if (grades.empty()) return 0.0;
            double sum = 0;
            for (double grade : grades) {
                sum += grade;
            }
            return sum / grades.size();
        }
        void addGrade(double grade) {
            grades.push_back(grade);  // نمره رو به لیست نمرات اضافه می‌کنه
        }

        void addAssignment(const string& assignment) {
            assignments.push_back(assignment);
        }
        void viewAssignments() const {
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

        void setGradeForStudent(const string& studentId, double grade) {
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

        void enrollStudent(const string& studentId) {
            if (studentIds.size() >= capacity) {
                cout << "Course is full. Cannot enroll more students.\n";
                return;
            }
            studentIds.push_back(studentId);
            grades.push_back(-1); // دانشجو ثبت نام شد، نمره اولیه -1
        }

        // گرفتن نمره‌ی دانشجو
        double getGradeForStudent(const string& studentId) const {
            for (int i = 0; i < studentIds.size(); i++) {
                if (studentIds[i] == studentId) {
                    return grades[i];
                }
            }
            return -1; // یعنی نمره‌ای وجود نداره
        }


        vector<string> getStudentIds() const {
            return studentIds;
        }

        vector<double> getGrades() const {
            return grades;
        }
    };

#endif

