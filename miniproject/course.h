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
        Course(std::string id, std::string name, Instructor* prof, int cap);

        // Getters و setters
        std::string getCourseId() const;
        void setCourseId(const std::string& id);

        std::string getCourseName() const;
        void setCourseName(const std::string& name);

        Instructor* getProfessor() const;
        void setProfessor(Instructor* prof);

        int getCapacity() const;
        void setCapacity(int cap);

        double getAverageGrade() const;
        void addGrade(double grade);
        void addAssignment(const string& assignment);
        void viewAssignments() const;

        void setGradeForStudent(const string& studentId, double grade);

        void enrollStudent(const string& studentId);

        // گرفتن نمره‌ی دانشجو
        double getGradeForStudent(const string& studentId) const;


        vector<string> getStudentIds() const;
        vector<double> getGrades() const;
    };

#endif

