/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// preprocessor directives
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "course.h"

using namespace std;

// to list all the student records read from the input file
void List(Course& course) {
    cout << course;
}

// to lookup a specific student record by the input student id. 
void Find(string id, Course& course) {
    // convert string to int
    int id_ = atoi(id.c_str());
    Student* temp = course.find(id_);
    // if id found output student info
    if (temp != NULL)
        cout << "ID: " << temp->getID() << '\n'
             << "First Name: " << temp->getFirstName() << '\n'
             << "Last Name: " << temp->getLastName() << '\n'
             << "Grade: " << temp->getGrade() << '\n'
             << "Status: " << temp->getStatus() << endl;
        // else id is not found in course
    else
        cout << "ID " << id_ << " not found." << endl;
    delete temp;
}

// main function
int main(int argc, char** argv)
{
    Course course;

    // reads filename if provided as argument
    if (argc > 2) {
        ifstream inputFile;
        inputFile.open("students.dat");
        if (inputFile.fail()) {
            cout << "Unable to read file: " << argv[2] << endl;
            return -1;
        }
        // input student records into the course
        inputFile >> course;
        inputFile.close();
    }
    // lists student record if command has 2 arguments
    if (argc == 3 && (argv[2] == (string)"list" || argv[2] == (string)"List"))
        List(course);
        // finds the student matching the id and displays student if command has 3 arguments
    else if (argc == 4 && (argv[2] == (string)"find" || argv[2] == (string)"Find"))
        Find(argv[3], course);
        // shows command usage
    else {
        cout << "./proj03 <input file> find <id>" << endl;
        cout << "./proj03 <input file> list" << endl;
    }
    return 0;
}
