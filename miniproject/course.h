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
        std::vector<double> grades;

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


    };

#endif

