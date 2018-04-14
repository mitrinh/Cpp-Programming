/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #1
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// preprocessor directives
#include "student.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

// to list all the student records read from the input file
void list(Student students[],int length) {
    for (int student = 0; student < length; student++) {
        cout << "ID: " << students[student].id << endl;
	cout << "First Name: " << students[student].firstName << endl;
	cout << "Last Name: " << students[student].lastName << endl;
	cout << "Grade: " << students[student].grade << '\n' << endl;
    }
}

// to lookup a specific student record by the input student id. 
void find(Student students[],string id,int length) {
    // convert string to int
    int newID = atoi(id.c_str());
    // find index of ID if any
    int index = find(newID,students,length);

    // display student
    if (index != -1) {
    cout << "ID: " << students[index].id << endl;
    cout << "First Name: " << students[index].firstName << endl;
    cout << "Last Name: " << students[index].lastName << endl;
    cout << "Grade: " << students[index].grade << '\n' << endl;
    }
}

// main function
int main(int argc, char** argv)
{
    Student students[35];
    // create student records
    ofstream outputFile;
    outputFile.open("students.dat");
    if (outputFile.fail()) {
        cout << "Unable to create file: " << argv[2] << endl;
        return -1;
    }
    outputFile << "John Doe 123456789 A" << endl;
    outputFile << "Bob Smith 598765432 B" << endl;
    outputFile << "Bill Jones 898745792 C" << endl;
    outputFile << "George Roberts 128920740 D" << endl;
    outputFile.close(); 

    int length = 0;
    // reads filename if provided as argument
    if (argc > 1) {
        length = read(argv[1], students);
    }
    // lists student record if command has 3 arguments
    if (argc == 3) {
        list (students,length);
    }
    // finds the student matching the id and displays student if command has 4 arguments
    else if (argc == 4) {
        find(students,argv[3],length);
    }
    // shows command usage
    else {
        cout << "./proj01 <input file> find <id>" << endl;
        cout << "./proj01 <input file> list" << endl;
    }
    return 0;
}

