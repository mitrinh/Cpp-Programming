/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// @file PartTime.h
#ifndef PARTTIME_H
#define PARTTIME_H

#include "student.h"

class PartTime : public Student{

    public:
        PartTime();
        PartTime(string firstName, string lastName, int id, char grade);
        virtual ~PartTime();
        virtual string getStatus() const;
};

#endif //PARTTIME_H
