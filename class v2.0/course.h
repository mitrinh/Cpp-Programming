/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #2
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// @file course.h
#ifndef COURSE_H
#define COURSE_H

#include "student.h"
#include <iostream>
using namespace std;

class Course {
    /**
    * @param is the input stream
    * @param course the course object reference
    * @return the input stream
    */
    friend istream& operator >> (istream& is, Course& course);

    /**
    * @param os the output stream
    * @param course the course object reference
    * @return the output stream
    */
    friend ostream& operator << (ostream& os, const Course& course);

public:
    static const int MAX_STUDENTS = 35;

    Course();

    /**
    * @param id the student id to search for
    * @param student reference to the match student object, if found
    * @return true if found.
    */
    bool find(int id,Student& student) const;

private: 
    void sort_(); /* extra credit */
    Student students[Course::MAX_STUDENTS];
    int studentCount;
};

#endif /* COURSE_H */