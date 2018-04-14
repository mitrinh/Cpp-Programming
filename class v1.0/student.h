/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #1
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// @file student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int id;
    char grade;
};

/**
* @param filename name of the input data file
* @param students[] an array of student records read from the file
*
* @return the number of student records read
*/
int read(string filename, Student students[]);
/**
* @param id the student id to search for
* @param students[] the list of student records
* @param length the number of student records in the array
*
* @return the array index of the match student record, otherwise it returns -1
*/
int find(int id, Student students[], int length);
#endif /* STUDENT_H */
