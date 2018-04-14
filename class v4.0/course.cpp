/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// preprocessor directives

#include <iostream>
#include "course.h"

using namespace std;

// inputs a student's info into a list
istream& operator >> (istream& is, Course& course) {
    // initializes to fulltime
    Student* student = new FullTime;
    // used to check if status is parttime or not
    string status;
    // used in case student is parttime
    Student* student2;
    //iterate and enqueue each student, make a new student each iteration
    while(is >> *student) {
        // read in status
        is >> status;
        // if parttime: copies student info to new student, deletes old student, and add student as parttime instead
        if (status == "PARTTIME") {
            student2 = new PartTime(student->getFirstName(),student->getLastName(),student->getID(),student->getGrade());
            delete student;
            student = student2;
        }
        course.students.enqueue(student);
        course.studentCount = course.students.getSize();
        student = new FullTime;
    }
    delete student;
    return is;
}

// lists the students in the course
ostream& operator << (ostream& os, const Course& course) {
    Student* student;
    // iterate through queue and put each student into os
    for (int i = 0; i < course.studentCount; i++) {
        student = iterateQueue(i, course.students);
        os << *student << endl;
        delete student;
    }
    return os;
}

Course::Course() {
    studentCount = 0;
}

//Student* Course::find(int id) const{
Student* Course::find(int id) const{
    Student* student;
    // iterate through queue and check with each student id until found
    for (int i = 0; i < this->studentCount; i++) {
        student = iterateQueue(i, this->students);
        if (id == student->getID()) {
            return student;
        }
	delete student;
    }
    // return null when id not in queue
    return NULL;
}

