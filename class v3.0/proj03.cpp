/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #3
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// preprocessor directives
#include "course.h"
#include <cstdlib>
#include <fstream>


using namespace std;

// to list all the student records read from the input file
void List(Course& course) {
    cout << course;
}

// to lookup a specific student record by the input student id. 
void Find(string id, Course& course) {
    // convert string to int
    int id_ = atoi(id.c_str());
    Student temp;
    // if id found output student info
    if (course.find(id_, temp))
        cout << "ID: " << temp.getID() << '\n'
            << "First Name: " << temp.getFirstName() << '\n'
            << "Last Name: " << temp.getLastName() << '\n'
            << "Grade: " << temp.getGrade() << '\n' << endl;
    // else id is not found in course
    else 
        cout << "ID: " << id_ << " not found." << endl;
}

// main function
int main(int argc, char** argv)
{
    Course course;
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
    outputFile << "George Roberts 128920740 D" << endl;;
    outputFile.close();
    
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
    if (argc == 3) 
        List(course);
    // finds the student matching the id and displays student if command has 3 arguments
    else if (argc == 4)
        Find(argv[3], course);
    // shows command usage
    else {
        cout << "./proj01 <input file> find <id>" << endl;
        cout << "./proj01 <input file> list" << endl;
    }
    return 0;
}
