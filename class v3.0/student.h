/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #3
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// @file student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {

    /**
    * @param is the input stream
    * @param course the student object reference
    * @return the input stream
    */
    friend istream& operator >> (istream& is, Student& student);

    /**
    * @param os the output stream
    * @param course the student object reference
    * @return the output stream
    */
    friend ostream& operator << (ostream& os, const Student& student);

    public:
        Student();
        Student(string firstName, string lastName, int id, char grade);

        /* setters and getters*/

        void setFirstName(string firstName);
        string getFirstName();

        void setLastName(string lastName);
        string getLastName();

        void setID(int id);
        int getID();

        void setGrade(char grade);
        char getGrade();

        /* setters and getters */

    private:
        string firstName;
        string lastName;
        int id;
        char grade;
};


#endif /* STUDENT_H */
