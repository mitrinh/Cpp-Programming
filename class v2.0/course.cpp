/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #2
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/


// preprocessor directives
#include "course.h"

using namespace std;

// inputs a student's info into a list
istream& operator >> (istream& is, Course& course) {
    // uses the other istream operator in student.cpp to read in student info
    for (int index = 0; is >> course.students[course.studentCount] && index < course.MAX_STUDENTS; index++) 
        // increase the number of students in the course
        course.studentCount++;
    // sort list by last name alphabetically
    course.sort_();
    return is;
}

// lists the students in the course
ostream& operator << (ostream& os, const Course& course) {
    Student temp;
    for (int index = 0; index < course.studentCount; index++) {
        temp = course.students[index];
        os << "ID: " << temp.getID() << '\n'
            << "First Name: " << temp.getFirstName() << '\n'
            << "Last Name: " << temp.getLastName() << '\n'
            << "Grade: " << temp.getGrade() << '\n' << endl;
    }
    return os;
}

Course::Course() {
    studentCount = 0;
}

bool Course::find(int id,Student& student) const{
    for (int index = 0; index < studentCount; index++) {
        student = students[index];
        if (id == student.getID())
            return true;
    }
    return false;
}

// sort list of students by last name alphabetically
void Course::sort_() {
    // used for swapping students
    Student temp;
    // nested loop to double check if list in correct order
    for (int index = 0; index < studentCount; index++) {
        // each iteration checks if that student is in the right spot
        for (int index_ = index; index_ < studentCount - index; index_++) {
            // swap places if last name of 1st student is higher than the next student's
            if ((index_ + 1) < studentCount) {
                // checks if student is in alphabetical order and if there is a next student
                if ((students[index_].getLastName() > students[index_ + 1].getLastName()) 
                        && ((index_ + 1) < studentCount)) {
                    temp = students[index_];
                    students[index_] = students[index_ + 1];
                    students[index_ + 1] = temp;
                }
            }
        }
    }
}

