/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

#include <iostream>
#include "PartTime.h"

using namespace std;

PartTime::PartTime() : Student() {
}

PartTime::PartTime(string firstName, string lastName, int id, char grade) : Student(firstName, lastName, id, grade) {
}

PartTime::~PartTime(){
}

string PartTime::getStatus() const{
    return "PARTTIME";
}