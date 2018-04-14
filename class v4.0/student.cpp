/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// preprocessor directives
#include <iostream>
#include "student.h"

using namespace std;

// inputs a student's info from a file
istream& operator >> (istream& is, Student& student) {
    string tempString;
    int tempInt;
    char tempChar;

    is >> tempString;
    student.setFirstName(tempString);
    is >> tempString;
    student.setLastName(tempString);
    is >> tempInt;
    student.setID(tempInt);
    is >> tempChar;
    student.setGrade(tempChar);

    return is;
}

// outputs the info of a student
ostream& operator << (ostream& os, const Student& student) {
    os << "ID: " << student.getID() << '\n'
       << "First Name: " << student.getFirstName() << '\n'
       << "Last Name: " << student.getLastName() << '\n'
       << "Grade: " << student.getGrade() << '\n'
       << "Status: " << student.getStatus() << endl;
    return os;
}

Student::Student() {
}

Student::Student(string firstName, string lastName, int id, char grade) {
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setID(id);
    this->setGrade(grade);
}

Student::~Student() {
}

// sets the student's first name
void Student::setFirstName(string firstName_) {
    this->firstName = firstName_;
}

// gets the student's first name
string Student::getFirstName() const{
    return this->firstName;
}

// sets the student's last name
void Student::setLastName(string lastName_) {
    this->lastName = lastName_;
}

// gets the student's last name
string Student::getLastName() const{
    return this->lastName;
}

// sets the student's id 
void Student::setID(int id_) {
    this->id = id_;
}

// return student's id
int Student::getID() const{
    return this->id;
}

// sets the student's grade
void Student::setGrade(char grade_) {
    this->grade = grade_;
}

// returns student's grade
char Student::getGrade() const{
    return this->grade;
}

