/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

#include <iostream>
#include "FullTime.h"

using namespace std;

FullTime::FullTime() : Student() {
}

FullTime::FullTime(string firstName, string lastName, int id, char grade) : Student(firstName, lastName, id, grade) {
}

FullTime::~FullTime(){
}

string FullTime::getStatus() const{
    return "FULLTIME";
}