/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #1
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// preprocessor directives
#include "student.h"
#include <fstream>
#include <iostream>

using namespace std;

// return the number of student records read
int read(string filename, Student students[]) {
    ifstream inputFile;
    // opens the file
    inputFile.open(filename.c_str());
    if (inputFile.fail()) {
        cout << "Unable to read file: " << filename << endl;
        return -1;
    }

    // reads data from file and makes a record for each student
    // reads a student for each iteration
    int length = 0;
    for(int studentCount = 0;!inputFile.eof();studentCount++) {
        inputFile >> students[studentCount].firstName >> students[studentCount].lastName >> 
            students[studentCount].id >> students[studentCount].grade;
        length = studentCount;
    }
    // close the file
    inputFile.close();
    // return length
    return length;
}

// return the array index of the match student record, otherwise it returns -1
int find(int id, Student students[], int length) {
    
    // match desired id to the correct student in each iteration
    for (int student = 0; student < length; student++) {
        if (id == students[student].id) {
            return student;
        }
    }

    // assume id isn't found
    cout << "Student with id " << id << " not found." << endl;
    return -1;
}
