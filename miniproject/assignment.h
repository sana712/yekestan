#pragma once
#include <iostream>
#include <string>
#include <vector>


class Assignment {
private:
    string assignmentId;
    string title;
    string description;
    string dueDate;


public:
    Assignment(string title, string desc, string due)
        : assignmentId("unknown"), title(title), description(desc), dueDate(due) {
    }

    Assignment(string id, string title, string desc, string due)
        : assignmentId(id), title(title), description(desc), dueDate(due) {
    }

    void submitAssignment() {
        cout << "Assignment " << title << " submitted." << endl;
    }

    void gradeAssignment(int grade) {
        cout << "Assignment " << title << " graded with " << grade << endl;
    }

    // Getter functions
    string getAssignmentId() const {
        return assignmentId;
    }

    string getTitle() const {
        return title;
    }

    string getDescription() const {
        return description;
    }

    string getDueDate() const {
        return dueDate;
    }

    // Setter functions
    void setAssignmentId(const string& newId) {
        assignmentId = newId;
    }

    void setTitle(const string& newTitle) {
        title = newTitle;
    }

    void setDescription(const string& newDescription) {
        description = newDescription;
    }

    void setDueDate(const string& newDueDate) {
        dueDate = newDueDate;
    }

};

