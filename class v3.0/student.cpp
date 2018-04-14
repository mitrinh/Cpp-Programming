/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #3
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// preprocessor directives
#include "student.h"
#include <iostream>

using namespace std;

// inputs a student's info from a file
istream& operator >> (istream& is, Student& student) {
    is >> student.firstName;
    is >> student.lastName;
    is >> student.id;
    is >> student.grade;
    // ignore endl char
    is.ignore();
    return is;
}

// outputs the info of a student
ostream& operator << (ostream& os, const Student& student) {
    os << student.firstName << ' ' <<student.lastName << ' ' << student.id << ' ' << student.grade << endl;
    return os;
}

Student::Student() {
    firstName = " ";
    lastName = " ";
    id = 0;
    grade = ' ';
}

Student::Student(string firstName, string lastName, int id, char grade) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->grade = grade;
}

// sets the student's first name
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

// gets the student's first name
string Student::getFirstName() {
    return firstName;
}

// sets the student's last name
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

// gets the student's last name
string Student::getLastName() {
    return lastName;
}

// sets the student's id 
void Student::setID(int id) {
    this->id = id;
}

// return student's id
int Student::getID() {
    return id;
}

// sets the student's grade
void Student::setGrade(char grade) {
    this->grade = grade;
}

// returns student's grade
char Student::getGrade() {
    return grade;
}
